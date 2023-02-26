/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:13:48 by gyim              #+#    #+#             */
/*   Updated: 2023/02/26 19:44:33 by gyim             ###   ########seoul.kr  */
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
		temp = check_plane(ray, (t_plane *)plane->content);
		if (target_object.obj == NULL
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		plane = plane->next;
	}
	return (target_object);
}

t_hit_info	check_plane(t_ray ray, t_plane *plane)
{
	t_hit_info	hit_info;
	double		n0;
	double		denominator;

	hit_info.obj = NULL;
	denominator = v3_inner_product_v3(plane->orientation, ray.orient);
	if (denominator == 0)
		return (hit_info);
	n0 = -v3_inner_product_v3(plane->orientation, plane->pos);
	hit_info.t = -(v3_inner_product_v3(plane->orientation, ray.pos) + n0);
	hit_info.t = hit_info.t / denominator;
	if (hit_info.t < 0)
		return (hit_info);
	hit_info.obj = (t_list *)plane;
	hit_info.point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info.t));
	if (sin(0.25 * hit_info.point.x) * sin(0.25 *hit_info.point.y) * sin(0.25 *hit_info.point.z) > 0)
		hit_info.color = plane->color;
	else
		hit_info.color.r = 1 - plane->color.r;
		hit_info.color.g = 1 - plane->color.g;
		hit_info.color.b = 1 - plane->color.b; 
	return (hit_info);
}
