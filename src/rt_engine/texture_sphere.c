/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:42:09 by gyim              #+#    #+#             */
/*   Updated: 2023/03/12 19:52:31 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_rgb	texture_sphere(t_sphere *sphere, t_hit_info *hit_info)
// {
// 	t_vec3	center_to_point;
// 	t_vec3	y_axis;
// 	t_vec3	point;
// 	t_vec3	color;
// 	double	phi_degree;
// 	double	theta_degree;
// 	double	unit_degree;
// 	int		x;
// 	int		y;
// 	int		pos;
// 	t_rgb	ret;

// 	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
// 	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
// 	point.x = v3_inner_product_v3(center_to_point, sphere->x_axis);
// 	point.y = v3_inner_product_v3(center_to_point, y_axis);
// 	point.z = v3_inner_product_v3(center_to_point, sphere->orientation);
// 	phi_degree = get_sphere_phi(point) / M_PI * 180.0;
// 	theta_degree = get_sphere_theta(point) / M_PI * 180.0;

// 	unit_degree = 15.0;
// 	phi_degree += 180.0;
// 	theta_degree += 90.0;
// 	x = phi_degree / 360.0 * sphere->texture.width;
// 	y = theta_degree / 180.0 * sphere->texture.height;
// 	pos = (y * sphere->texture->img.size_l + x * (sphere.texture->img.bpp / 8));
// 	ret.x = (pos >> 16) & 0xFF;
// 	ret.y = (pos >> 8) & 0xFF;
// 	ret.z = pos & 0xFF;
// 	return (ret);
// }