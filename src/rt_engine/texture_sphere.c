/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:42:09 by gyim              #+#    #+#             */
/*   Updated: 2023/03/24 15:56:41 by jaehyuki         ###   ########.fr       */
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
	unsigned int	image_value;
	t_rgb			ret;


	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
	sphere->x_axis = v3_unit(v3_cross_product_ds(sphere->orientation, 0.0, -1.0, 0.0));
	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
	point.x = v3_inner_product_v3(center_to_point, sphere->x_axis);
	point.y = v3_inner_product_v3(center_to_point, y_axis);
	point.z = v3_inner_product_v3(center_to_point, sphere->orientation);
	phi_degree = get_sphere_phi(point) / M_PI * 180.0;
	theta_degree = get_sphere_theta(point) / M_PI * 180.0;
	x = (phi_degree / 360.0) * sphere->texture.width;
	if (x == sphere->texture.width)
		x--;
	y = (theta_degree / 180.0) * sphere->texture.height;
	if (y == sphere->texture.height)
		y--;
	image_value = sphere->texture.img->data[y * sphere->texture.width + x];
	ret.x = ((image_value >> 16) & 0xFF) / 256.0;
	ret.y = ((image_value >> 8) & 0xFF) / 256.0;
	ret.z = (image_value & 0xFF) / 256.0;
	return (ret);
}