/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:27:19 by gyim              #+#    #+#             */
/*   Updated: 2023/03/09 17:00:36 by gyim             ###   ########seoul.kr  */
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
	double	phi_degree;
	double	theta_degree;
	double	unit_degree;

	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
	point.x = v3_inner_product_v3(center_to_point, sphere->x_axis);
	point.y = v3_inner_product_v3(center_to_point, y_axis);
	point.z = v3_inner_product_v3(center_to_point, sphere->orientation);
	phi_degree = get_sphere_phi(point) / M_PI * 180.0;
	theta_degree = get_sphere_theta(point) / M_PI * 180.0;
	unit_degree = 15.0;
	if (phi_degree < 0)
		phi_degree -= unit_degree;
	if (theta_degree < 0)
		theta_degree -= unit_degree;
	if (((int)(phi_degree / unit_degree)
		 + (int)(theta_degree / unit_degree)) % 2 == 0)
		color = sphere->color;
	else
		v3_set(&color, 1.0, 1.0, 1.0);
	return (color);
}

t_rgb	checker_cylinder_body(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	double	height;
	int		width;
	t_rgb	color;
	t_vec3	dr;
	double	theta;
	t_vec3	dx;
	t_vec3	dy;
	double	degree;
	double	length;

	width = 5;
	center_to_point = v3_minus_v3(hit_info->point, cylinder->pos);
	height = v3_inner_product_v3(cylinder->orientation, center_to_point);
	dr = v3_unit(v3_minus_v3(center_to_point,
				v3_mul_d(cylinder->orientation, height)));
	dx = cylinder->x_axis;
	dy = v3_cross_product_v3(cylinder->orientation, dx);
	theta = atan(v3_inner_product_v3(dr, dy) / v3_inner_product_v3(dr, dx));
	degree = theta / M_PI * 180;
	if (degree < 0)
		degree -= 5.0;
	length = (height / width);
	if (length < 0)
		length -= width;
	if (((int)length + (int)degree / 5) % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		color = hit_info->color;
	return (color);
}

t_rgb	checker_cylinder_head(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	t_rgb	color;
	double	height;
	t_vec3	dr;
	double	theta;
	t_vec3	dx;
	t_vec3	dy;
	double	degree;

	center_to_point = v3_minus_v3(hit_info->point, cylinder->pos);
	height = v3_inner_product_v3(cylinder->orientation, center_to_point);
	dr = v3_unit(v3_minus_v3(center_to_point,
				v3_mul_d(cylinder->orientation, height)));
	dx = cylinder->x_axis;
	dy = v3_cross_product_v3(cylinder->orientation, dx);
	theta = atan(v3_inner_product_v3(dr, dy) / v3_inner_product_v3(dr, dx));
	degree = theta / M_PI * 180;
	if (degree < 0)
		degree -= 5;
	if ((int)(degree) / 5 % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		color = hit_info->color;
	return (color);
}