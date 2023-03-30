/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:35:40 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 15:39:38 by gyim             ###   ########seoul.kr  */
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
	if (hit_info.obj == NULL && hit_info2.obj == NULL)
		return (hit_info);
	else if (hit_info.obj != NULL && hit_info2.obj == NULL)
		return (hit_info);
	else if (hit_info.obj == NULL && hit_info2.obj != NULL)
		return (hit_info2);
	if (hit_info.t < hit_info2.t)
		return (hit_info);
	else
		return (hit_info2);
}

t_cone_var	get_cone_var(t_ray ray, t_cone *cone)
{
	t_cone_var	cone_var;

	cone_var.cone_orient = v3_unit(v3_mul_d(cone->orientation, -1));
	cone_var.peak = v3_plus_v3(cone->pos,
			v3_mul_d(v3_unit(cone->orientation), cone->height / 2.0));
	cone_var.p2p0 = v3_minus_v3(ray.pos, cone_var.peak);
	cone_var.theta = atan((cone->diameter / 2.0) / cone->height);
	cone_var.ray_orient = ray.orient;
	cone_var.cos_thata = cos(cone_var.theta);
	return (cone_var);
}

void	get_cone_bottom(t_hit_info *hit_info, t_ray ray, t_list *cone_list)
{
	t_cone		*cone;
	t_vec3		center;
	t_vec3		normal;

	hit_info->obj = NULL;
	hit_info->ray = ray;
	cone = (t_cone *)cone_list->content;
	normal = v3_mul_d(cone->orientation, -1.0);
	center = v3_plus_v3(cone->pos, v3_mul_d(normal, cone->height / 2.0));
	hit_info->t = check_disk(ray, center, normal, cone->diameter / 2.0);
	if (hit_info->t < 0)
		return ;
	hit_info->normal = normal;
	hit_info->obj = cone_list;
	hit_info->point = v3_plus_v3(ray.pos,
			v3_mul_d(ray.orient, hit_info->t));
	hit_info->color = cone->color;
	hit_info->ray = ray;
}
