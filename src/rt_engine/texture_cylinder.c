/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:46:39 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/26 18:40:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// p1 :lower circle center

t_rgb   texture_cylinder_body(t_cylinder *cylinder, t_hit_info *hit_info)
{
	t_vec3	p1;
	t_vec3	p1_to_point;
	t_vec3	y_axis;
	t_vec3	dr;
	t_vec3	dh;
	double	theta;
	double	height;
	int		x;
	int 	y;
	unsigned int	image_value;

	cylinder->x_axis = v3_unit(v3_cross_product_ds(cylinder->orientation,
				0.0, -1.0, 0.0));
	p1 = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, -cylinder->height / 2.0));
	p1_to_point = v3_minus_v3(hit_info->point, p1);
	height = v3_inner_product_v3(p1_to_point, cylinder->orientation);
	y_axis = v3_unit(v3_cross_product_v3(cylinder->orientation, cylinder->x_axis));
	dh = v3_mul_d(cylinder->orientation, height);
	dr = v3_minus_v3(p1_to_point, dh);
	theta = get_circle_theta(dr, cylinder->x_axis, y_axis);
	x = theta / (2 * M_PI) * cylinder->texture.width;
	y = height / cylinder->height * cylinder->texture.height;
	image_value = cylinder->texture.img->data[y * cylinder->texture.width + x];
	return (ft_i_to_rgb(image_value));
}

double	get_circle_theta(t_vec3 dr, t_vec3 x_axis, t_vec3 y_axis)
{
	double	x;
	double	y;
	double	theta;

	x = v3_inner_product_v3(dr, x_axis);
	y = v3_inner_product_v3(dr, y_axis);
	// printf("x : %f, y : %f\n",x ,y);
	theta = atan2(y, x);
	// printf("theta1 : %f\n", theta);
	if (theta < 0)
		return (theta + 2 * M_PI);
	else
		return (theta);
}
