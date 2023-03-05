/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:37:58 by gyim              #+#    #+#             */
/*   Updated: 2023/03/05 12:01:58 by gyim             ###   ########seoul.kr  */
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
	t_hit_info		hit_info2;

	get_cylinder_body(&hit_info, ray, cy);
	get_cylinder_head(&hit_info2, ray, cy);
	if (hit_info2.obj != NULL
		&& (hit_info.obj == NULL || hit_info2.t < hit_info.t))
		return (hit_info2);
	return (hit_info);
}

double	find_root(double t[2], double coeff[3], double discriminant)
{
	double	temp;

	t[0] = (-coeff[1] - sqrt(discriminant)) / (2.0 * coeff[0]);
	t[1] = (-coeff[1] + sqrt(discriminant)) / (2.0 * coeff[0]);
	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
	return (find_t(t[0], t[1]));
}

t_cylinder_var	get_cylinder_var(t_ray ray, t_cylinder *cylinder)
{
	t_cylinder_var	cylinder_var;

	cylinder_var.p0 = ray.pos;
	cylinder_var.p1 = v3_minus_v3(cylinder->pos,
			v3_mul_d(v3_unit(cylinder->orientation), cylinder->height / 2.0));
	cylinder_var.p2 = v3_plus_v3(cylinder->pos,
			v3_mul_d(v3_unit(cylinder->orientation), cylinder->height / 2.0));
	cylinder_var.delta_p = v3_minus_v3(cylinder_var.p2, cylinder_var.p1);
	cylinder_var.dp = v3_inner_product_v3(ray.orient, cylinder_var.delta_p);
	cylinder_var.p01 = v3_minus_v3(cylinder_var.p0, cylinder_var.p1);
	cylinder_var.pp = v3_inner_product_v3(cylinder_var.delta_p,
			cylinder_var.delta_p);
	return (cylinder_var);
}
