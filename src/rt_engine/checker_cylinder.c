/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:22:09 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 19:51:51 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_cylinder_body(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	double	height;
	double	theta;
	int		width;
	t_vec3	dr;
	t_vec3	y_axis;

	cylinder->x_axis = v3_unit(v3_cross_product_ds(cylinder->orientation,
				0.0, -1.0, 0.0));
	width = M_PI * cylinder->diameter / cylinder->texture.divid;
	center_to_point = v3_minus_v3(hit_info->point, cylinder->pos);
	height = v3_inner_product_v3(cylinder->orientation, center_to_point);
	dr = v3_unit(v3_minus_v3(center_to_point,
				v3_mul_d(cylinder->orientation, height)));
	y_axis = v3_cross_product_v3(cylinder->orientation, cylinder->x_axis);
	theta = atan(v3_inner_product_v3(dr, y_axis)
			/ v3_inner_product_v3(dr, cylinder->x_axis));
	return (get_cylinder_checker_color(theta, height, width, hit_info));
}

t_rgb	get_cylinder_checker_color(double theta,
	double height, int width, t_hit_info *hit_info)
{
	t_rgb	color;

	theta = theta / M_PI * 180;
	theta = theta / (width);
	if (theta < 0)
		theta -= width;
	height = (height / width);
	if (height < 0)
		height -= width;
	printf("%d\n", ((int)height + (int)theta));
	if (((int)height + (int)theta) % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		color = hit_info->color;
	return (color);

}


t_rgb	checker_cylinder_head(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	t_rgb	color;
	t_vec3	dr;
	double	theta;
	t_vec3	dy;
	double	degree;

	center_to_point = v3_minus_v3(hit_info->point, cylinder->pos);
	dr = v3_minus_v3(center_to_point,
			v3_mul_d(cylinder->orientation, cylinder->height / 2.0));
	cylinder->x_axis = v3_unit(v3_cross_product_ds(cylinder->orientation, 0.0, -1.0, 0.0));
	dy = v3_unit(v3_cross_product_v3(cylinder->orientation, cylinder->x_axis));
	theta = atan(v3_inner_product_v3(dr, dy) / v3_inner_product_v3(dr, cylinder->x_axis));
	degree = theta / M_PI * 180;
	if (degree < 0)
		degree -= 5;
	if ((int)(degree) / cylinder->texture.divid % 2 == 0)
		v3_set(&color, 0.0, 0.0, 0.0);
	else
		color = cylinder->color;
	return (color);
}