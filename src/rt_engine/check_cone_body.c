/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cone_body.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:59:11 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 15:41:33 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cone_body(t_hit_info *hit_info, t_ray ray, t_list *cone_list)
{
	double		discriminant;
	t_cone_var	variable;
	t_cone		*cone;

	hit_info->obj = NULL;
	cone = (t_cone *)cone_list->content;
	variable = get_cone_var(ray, cone);
	get_cone_coeff(ray, cone, &variable);
	discriminant = pow(variable.coeff[1], 2.0) - 4.0 * variable.coeff[0]
		* variable.coeff[2];
	if (discriminant < 0)
		return ;
	find_root(variable.t, variable.coeff, discriminant);
	hit_info->t = check_corn_root(ray, cone, variable);
	if (hit_info->t < 0)
		return ;
	get_cone_body_hit_point(hit_info, cone_list, ray, variable);
}

void	get_cone_coeff(t_ray ray, t_cone *cone,
		t_cone_var *variable)
{
	double	ray_dir_dot_orient;

	(void)ray;
	(void)cone;
	ray_dir_dot_orient = v3_inner_product_v3(variable->ray_orient,
			variable->cone_orient);
	variable->coeff[0] = pow(ray_dir_dot_orient, 2.0)
		- pow(variable->cos_thata, 2.0);
	variable->coeff[1] = 2.0 * ((ray_dir_dot_orient
				* v3_inner_product_v3(variable->p2p0, variable->cone_orient))
			- v3_inner_product_v3(variable->ray_orient, variable->p2p0)
			* pow(variable->cos_thata, 2.0));
	variable->coeff[2] = pow(v3_inner_product_v3(variable->p2p0,
				variable->cone_orient), 2.0)
		- v3_inner_product_v3(variable->p2p0, variable->p2p0)
		* pow(variable->cos_thata, 2.0);
}

void	get_cone_body_hit_point(t_hit_info *hit_info, t_list *cone_list,
				t_ray ray, t_cone_var variable)
{
	t_cone	*cone;
	t_vec3	peak_to_hit;
	double	beta;
	t_vec3	temp;

	cone = (t_cone *)cone_list->content;
	hit_info->obj = cone_list;
	hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info->t));
	peak_to_hit = v3_minus_v3(hit_info->point, variable.peak);
	beta = sqrt(v3_inner_product_v3(peak_to_hit, peak_to_hit));
	temp = v3_mul_d(variable.cone_orient, beta);
	temp = v3_div_d(temp, v3_inner_product_v3(v3_unit(variable.cone_orient),
				v3_unit(peak_to_hit)));
	hit_info->normal = v3_unit(v3_minus_v3(peak_to_hit, temp));
	hit_info->color = cone->color;
	hit_info->ray = ray;
}

double	check_corn_root(t_ray ray, t_cone *cone, t_cone_var variable)
{
	t_vec3	edge;
	t_vec3	point;
	double	alpha;

	point = v3_plus_v3(ray.pos, v3_mul_d(variable.ray_orient, variable.t[0]));
	edge = v3_minus_v3(point, variable.peak);
	alpha = v3_inner_product_v3(edge, variable.cone_orient);
	if (alpha < 0 || alpha > cone->height)
		variable.t[0] = -1.0;
	point = v3_plus_v3(ray.pos, v3_mul_d(variable.ray_orient, variable.t[1]));
	edge = v3_minus_v3(point, variable.peak);
	alpha = v3_inner_product_v3(edge, variable.cone_orient);
	if (alpha < 0 || alpha > cone->height)
		variable.t[1] = -1.0;
	if (variable.t[0] > variable.t[1])
		swap_double(&variable.t[0], &variable.t[1]);
	if (variable.t[0] < 0)
	{
		if (variable.t[1] < 0)
			return (-1.0);
		else
			return (variable.t[1]);
	}
	else
		return (variable.t[0]);
}