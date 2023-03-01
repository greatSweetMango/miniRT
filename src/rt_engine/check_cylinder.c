/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:37:58 by gyim              #+#    #+#             */
/*   Updated: 2023/03/01 18:28:31 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_all_cylinder(t_ray ray, t_list *cylinder)
{
	t_hit_info	target_object;
	t_hit_info	temp;

	target_object.obj = NULL;
	while (cylinder != NULL)
	{
		temp = check_cylinder(ray, cylinder);
		if (target_object.obj == NULL
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		cylinder = cylinder->next;
	}
	return (target_object);
}

t_hit_info	check_cylinder(t_ray ray, t_list *cy)
{
	t_hit_info		hit_info;
	double			coeff[3];
	double			discriminant;
	double			t[2];
	double			alpha[2];
	t_cylinder_var	variable;
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)cy->content;
	hit_info.obj = NULL;
	variable = get_cylinder_var(ray, cylinder);
	get_cylinder_coeff(coeff, ray, cylinder, variable);
	discriminant = pow(coeff[1], 2.0) - 4 * coeff[0] * coeff[2];
	if (discriminant < 0)
		return (hit_info);
	t[0] = (-coeff[1] - sqrt(discriminant)) / (2.0 * coeff[0]);
	t[1] = (-coeff[1] + sqrt(discriminant)) / (2.0 * coeff[0]);
	hit_info.t = find_t(t[0], t[1]);
	if (hit_info.t < 0)
		return (hit_info);
	get_cylinder_alpha(alpha, t, ray, variable);
	if ((alpha[0] < 0 || alpha[0] > 1)
		&& (alpha[1] < 0 || alpha[1] > 1))
		return (hit_info);
	hit_info.obj = cy;
	hit_info.point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info.t));
	hit_info.color = cylinder->color;
	return (hit_info);
}

t_cylinder_var	get_cylinder_var(t_ray ray, t_cylinder *cylinder)
{
	t_cylinder_var	cylinder_var;

	cylinder_var.p0 = ray.pos;
	cylinder_var.p1 = v3_plus_v3(cylinder->pos,
			v3_mul_d(v3_unit(cylinder->orientation),-cylinder->height / 2));
	cylinder_var.p2 = v3_plus_v3(cylinder->pos,
			v3_mul_d(v3_unit(cylinder->orientation),cylinder->height));
	cylinder_var.delta_p = v3_minus_v3(cylinder_var.p2, cylinder_var.p1);
	cylinder_var.dp = v3_inner_product_v3(ray.orient, cylinder_var.delta_p);
	cylinder_var.p01 = v3_minus_v3(cylinder_var.p0, cylinder_var.p1);
	cylinder_var.pp = v3_inner_product_v3(cylinder_var.delta_p,
			cylinder_var.delta_p);
	return (cylinder_var);
}

void	get_cylinder_coeff(double coeff[3], t_ray ray, t_cylinder *cylinder,
	t_cylinder_var variable)
{
	coeff[0] = v3_inner_product_v3(ray.orient, ray.orient)
		- pow(variable.dp, 2.0) / variable.pp;
	coeff[1] = 2.0 * (v3_inner_product_v3(variable.p01, ray.orient)
			- v3_inner_product_v3(variable.p01, variable.delta_p) * variable.dp
			/ variable.pp);
	coeff[2] = v3_inner_product_v3(variable.p01, variable.p01)
		- pow(v3_inner_product_v3(variable.p01, variable.delta_p), 2.0)
		/ variable.pp;
	coeff[2] -= pow(cylinder->diameter / 2.0, 2.0);
}

void	get_cylinder_alpha(double alpha[2], double mu[2],
	t_ray ray, t_cylinder_var variable)
{
	alpha[0] = v3_inner_product_v3(variable.p0, variable.delta_p)
		+ mu[0] * v3_inner_product_v3(ray.orient, variable.delta_p)
		- v3_inner_product_v3(variable.p1, variable.delta_p);
	alpha[0] /= variable.pp;
	alpha[1] = v3_inner_product_v3(variable.p0, variable.delta_p)
		+ mu[1] * v3_inner_product_v3(ray.orient, variable.delta_p)
		- v3_inner_product_v3(variable.p1, variable.delta_p);
	alpha[1] /= variable.pp;
}
