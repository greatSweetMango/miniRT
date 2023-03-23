/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_body.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:29:34 by gyim              #+#    #+#             */
/*   Updated: 2023/03/23 17:51:02 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_body(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	double			discriminant;
	t_cylinder_var	variable;
	t_cylinder		*cylinder;

	hit_info->obj = NULL;
	cylinder = (t_cylinder *)cy->content;
	variable = get_cylinder_var(ray, cylinder);
	get_cylinder_coeff(ray, cylinder, &variable);
	discriminant = pow(variable.coeff[1], 2.0) - 4.0 * variable.coeff[0]
		* variable.coeff[2];
	if (discriminant < 0)
		return ;
	hit_info->t = find_root(variable.t, variable.coeff, discriminant);
	if (hit_info->t < 0)
		return ;
	get_cylinder_alpha(&variable);
	if (variable.alpha[0] < 0 || variable.alpha[0] > 1)
		return ;
	get_cylinder_body_hit_point(hit_info, cy, ray, variable);
	// hit_info->color = checker_cylinder_body(cylinder, hit_info);
	hit_info->color = get_cylinder_body_color(cylinder, hit_info);
}

t_rgb	get_cylinder_body_color(t_cylinder *cylinder, t_hit_info *hit_info)
{
	if (cylinder->texture.type == TT_CHECKER)
		return checker_cylinder_body(cylinder, hit_info);
	// else if (cylinder->texture.type == TT_IMAGE)
	// 	return texture_cylinder_body(cylinder, hit_info);
	else
		return cylinder->color;
}
void	get_cylinder_coeff(t_ray ray, t_cylinder *cylinder,
		t_cylinder_var *variable)
{
	variable->coeff[0] = v3_inner_product_v3(ray.orient, ray.orient)
		- pow(variable->dp, 2.0) / variable->pp;
	variable->coeff[1] = 2.0 * (v3_inner_product_v3(variable->p01, ray.orient)
			- v3_inner_product_v3(variable->p01, variable->delta_p)
			* variable->dp / variable->pp);
	variable->coeff[2] = v3_inner_product_v3(variable->p01, variable->p01)
		- pow(v3_inner_product_v3(variable->p01, variable->delta_p), 2.0)
		/ variable->pp;
	variable->coeff[2] -= pow(cylinder->diameter / 2.0, 2.0);
}

void	get_cylinder_alpha(t_cylinder_var *variable)
{
	variable->alpha[0] = v3_inner_product_v3(variable->p0, variable->delta_p)
		+ variable->t[0] * variable->dp
		- v3_inner_product_v3(variable->p1, variable->delta_p);
	variable->alpha[0] /= variable->pp;
	variable->alpha[1] = v3_inner_product_v3(variable->p0, variable->delta_p)
		+ variable->t[1] * variable->dp
		- v3_inner_product_v3(variable->p1, variable->delta_p);
	variable->alpha[1] /= variable->pp;
}

void	get_cylinder_body_hit_point(t_hit_info *hit_info, t_list *cy,
				t_ray ray, t_cylinder_var variable)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)cy->content;
	hit_info->obj = cy;
	hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info->t));
	hit_info->normal = v3_minus_v3(hit_info->point,
			v3_plus_v3(variable.p1,
				v3_mul_d(variable.delta_p, variable.alpha[0])));
	hit_info->normal = v3_unit(hit_info->normal);
	hit_info->color = cylinder->color;
	hit_info->ray = ray;
}
