/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:27:19 by gyim              #+#    #+#             */
/*   Updated: 2023/03/08 18:14:43 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_plane(t_plane *plane, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	double	alpha;
	double	beta;
	t_rgb	color;
	int		width;

	width = 100;
	center_to_point = v3_minus_v3(hit_info->point, plane->pos);
	alpha = v3_inner_product_v3(plane->dx, center_to_point);
	beta = v3_inner_product_v3(plane->dy, center_to_point);
	if (alpha < 0)
		alpha = alpha - width;
	if (beta < 0)
		beta = beta - width;
	if (((int)(alpha / width) + (int)(beta / width)) % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		v3_set(&color, 1.0, 1.0, 1.0);
	return (color);
}

t_rgb	checker_sphere(t_sphere *sphere, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	t_vec3	y_axis;
	t_vec3	point;
	t_vec3	color;

	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
	point.x = v3_inner_product_v3(center_to_point, sphere->x_axis);
	point.y = v3_inner_product_v3(center_to_point, y_axis);
	point.z = v3_inner_product_v3(center_to_point, sphere->orientation);
	if (((int)(get_sphere_phi(point) / M_PI * 45)
		 + (int)(get_sphere_theta(point) / M_PI * 45)) % 2 == 0)
		color = sphere->color;
	else
		v3_set(&color, 1.0, 1.0, 1.0);
	return (color);
}
