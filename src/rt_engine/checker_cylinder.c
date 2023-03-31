/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:22:09 by gyim              #+#    #+#             */
/*   Updated: 2023/03/31 14:24:42 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_cylinder_body(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	double	height;
	double	theta;
	t_vec3	dr;
	t_vec3	y_axis;

	cylinder->x_axis = v3_unit(v3_cross_product_ds(cylinder->orientation,
				0.0, -1.0, 0.0));
	center_to_point = v3_minus_v3(hit_info->point, cylinder->low_center);
	height = v3_inner_product_v3(cylinder->orientation, center_to_point);
	dr = v3_unit(v3_minus_v3(center_to_point,
				v3_mul_d(cylinder->orientation, height)));
	y_axis = v3_cross_product_v3(cylinder->orientation, cylinder->x_axis);
	theta = atan2(v3_inner_product_v3(dr, y_axis),
			v3_inner_product_v3(dr, cylinder->x_axis));
	return (get_cylinder_body_checker_color(theta, height, cylinder, hit_info));
}

t_rgb	get_cylinder_body_checker_color(double theta,
	double height, t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_rgb	color;
	double	unit_degree;
	double	unit_height;

	unit_degree = 2 * M_PI / cylinder->texture.divid;
	unit_height = cylinder->height / cylinder->texture.divid;
	if (theta < 0)
		theta += 2 * M_PI;
	theta = theta / unit_degree;
	height = height / unit_height;
	if (((int)height + (int)theta) % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		color = hit_info->color;
	return (color);
}

t_rgb	checker_cylinder_head(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	t_vec3	dr;
	double	theta;
	t_vec3	dy;

	center_to_point = v3_minus_v3(hit_info->point, cylinder->pos);
	dr = v3_minus_v3(center_to_point,
			v3_mul_d(cylinder->orientation, cylinder->height / 2.0));
	cylinder->x_axis = v3_unit(
			v3_cross_product_ds(cylinder->orientation, 0.0, -1.0, 0.0));
	dy = v3_unit(v3_cross_product_v3(cylinder->orientation, cylinder->x_axis));
	theta = atan2(v3_inner_product_v3(dr, dy),
			v3_inner_product_v3(dr, cylinder->x_axis));
	return (get_cylinder_head_checker_color(theta, cylinder, hit_info));
}

t_rgb	get_cylinder_head_checker_color(
		double theta, t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_rgb	color;
	double	unit_degree;

	unit_degree = 2 * M_PI / cylinder->texture.divid;
	if (theta < 0)
		theta += 2 * M_PI;
	theta = theta / unit_degree;
	if ((int)theta % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		color = hit_info->color;
	return (color);
}
