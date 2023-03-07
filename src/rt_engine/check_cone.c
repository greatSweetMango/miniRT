/* ************************************************************************** *//*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:35:40 by gyim              #+#    #+#             */
/*   Updated: 2023/03/05 11:55:16 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_all_cone(t_ray ray, t_list *cone)
{
	t_hit_info	target_object;
	t_hit_info	temp;

	target_object.obj = NULL;
	while (cone != NULL)
	{
		temp = check_cone(ray, cone);
		if (target_object.obj == NULL
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		cone = cone->next;
	}
	return (target_object);
}

t_hit_info	check_cone(t_ray ray, t_list *cone)
{
	t_hit_info	hit_info;
	t_hit_info	hit_info2;

	get_cone_body(&hit_info, ray, cone);
	get_cone_bottom(&hit_info2, ray, cone);
	if (hit_info2.obj != NULL
		&& (hit_info.obj == NULL || hit_info2.t < hit_info.t))
		return (hit_info2);
	return (hit_info);
}

t_cone_var	get_cone_var(t_ray ray, t_cone *cone)
{
	t_cone_var	cone_var;

	(void)ray;
	cone_var.cone_orient = v3_unit(v3_mul_d(cone->orientation, -1));
	cone_var.peak = v3_plus_v3(cone->pos,
			v3_mul_d(v3_unit(cone->orientation), cone->height / 2.0));
	cone_var.p2p0 = v3_minus_v3(ray.pos, cone_var.peak);
	cone_var.theta = atan((cone->diameter / 2.0) / cone->height);
	cone_var.ray_orient = ray.orient;
	cone_var.cos_thata = cos(cone_var.theta);
	return (cone_var);
}
