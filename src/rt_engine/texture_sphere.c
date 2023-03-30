/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:42:09 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 17:42:17 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	texture_sphere(t_sphere *sphere, t_hit_info *hit_info)
{
	t_vec3			center_to_point;
	t_vec3			y_axis;
	t_vec3			point;
	int				x;
	int				y;

	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
	sphere->x_axis = v3_unit(v3_cross_product_ds(
				sphere->orientation, 0.0, -1.0, 0.0));
	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
	point = change_of_basis(center_to_point,
			sphere->x_axis, y_axis, sphere->orientation);
	get_sphere_texture_point(&x, &y, sphere, point);
	return (ft_i_to_rgb(
			sphere->texture.img->data[y * sphere->texture.width + x]));
}

t_vec3	change_of_basis(t_vec3	center_to_point,
	t_vec3 x_axis, t_vec3 y_axis, t_vec3 z_axis)
{
	t_vec3	point;

	point.x = v3_inner_product_v3(center_to_point, x_axis);
	point.y = v3_inner_product_v3(center_to_point, y_axis);
	point.z = v3_inner_product_v3(center_to_point, z_axis);
	return (point);
}

void	get_sphere_texture_point(int *x, int *y, t_sphere *sphere, t_vec3 point)
{
	double	phi_degree;
	double	theta_degree;

	phi_degree = get_sphere_phi(point) / M_PI * 180.0;
	theta_degree = get_sphere_theta(point) / M_PI * 180.0;
	*x = (phi_degree / 360.0) * sphere->texture.width;
	if (*x == sphere->texture.width)
		(*x)--;
	*y = (theta_degree / 180.0) * sphere->texture.height;
	if (*y == sphere->texture.height)
		(*y)--;
}
