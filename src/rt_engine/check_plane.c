/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:13:48 by gyim              #+#    #+#             */
/*   Updated: 2023/03/01 18:12:54 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_all_plane(t_ray ray, t_list *plane)
{
	t_hit_info	target_object;
	t_hit_info	temp;

	target_object.obj = NULL;
	while (plane != NULL)
	{
		temp = check_plane(ray, plane);
		if (target_object.obj == NULL
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		plane = plane->next;
	}
	return (target_object);
}

t_hit_info	check_plane(t_ray ray, t_list *pl)
{
	t_hit_info	hit_info;
	double		n0;
	double		denominator;
	t_plane		*plane;

	hit_info.obj = NULL;
	plane = (t_plane *)pl->content;
	denominator = v3_inner_product_v3(plane->orientation, ray.orient);
	if (denominator == 0)
		return (hit_info);
	n0 = -v3_inner_product_v3(plane->orientation, plane->pos);
	hit_info.t = -(v3_inner_product_v3(plane->orientation, ray.pos) + n0);
	hit_info.t = hit_info.t / denominator;
	if (hit_info.t < 0)
		return (hit_info);
	hit_info.obj = pl;
	hit_info.point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info.t));
	hit_info.normal = v3_unit(plane->orientation);
	// if (sin(0.25 * hit_info.point.x) * sin(0.25 *hit_info.point.y) * sin(0.25 *hit_info.point.z) > 0)
	// 	hit_info.color = plane->color;
	// else
	// 	hit_info.color.r = 1 - plane->color.r;
	// 	hit_info.color.g = 1 - plane->color.g;
	// 	hit_info.color.b = 1 - plane->color.b;
	hit_info.color.r = plane->color.r;
	hit_info.color.g = plane->color.g;
	hit_info.color.b = plane->color.b;
	
	return (hit_info);
}
