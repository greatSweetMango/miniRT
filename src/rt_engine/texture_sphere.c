/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:42:09 by gyim              #+#    #+#             */
/*   Updated: 2023/03/18 19:36:05 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	texture_sphere(t_sphere *sphere, t_hit_info *hit_info)
{
	t_vec3			center_to_point;
	t_vec3			y_axis;
	t_vec3			point;
	double			phi_degree;
	double			theta_degree;
	int				x;
	int				y;
	int				image_value;
	t_rgb			ret;
	char			*data;


	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
	point.x = v3_inner_product_v3(center_to_point, sphere->x_axis);
	point.y = v3_inner_product_v3(center_to_point, y_axis);
	point.z = v3_inner_product_v3(center_to_point, sphere->orientation);
	phi_degree = get_sphere_phi(point) / M_PI * 180.0;
	theta_degree = get_sphere_theta(point) / M_PI * 180.0;
	// printf("%f %f\n", theta_degree, phi_degree);
	x = (phi_degree / 360.0) * sphere->texture.width;
	if (x == sphere->texture.width)
		x--;
	y = (theta_degree / 180.0) * sphere->texture.height;
	if (y == sphere->texture.height)
		y--;
	// int pos = (y * size_line + x * (bits_per_pixel / 8));
	// printf("%d %d\n", y, x);
	data = (char*)sphere->texture.img->data;
	// image_value = sphere->texture.img->data + (y * sphere->texture.height + x);
	image_value = *(data + (y * sphere->texture.img->size_l + x * (sphere->texture.img->bpp / 8)));
	ret.x = ((image_value >> 16) & 0xFF) / 256.0;
	ret.y = ((image_value >> 8) & 0xFF) / 256.0;
	ret.z = (image_value & 0xFF) / 256.0;
	return (ret);
}