/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:21:51 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 18:39:23 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_sphere(t_sphere *sphere, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	t_vec3	y_axis;
	t_vec3	point;
	double	phi_degree;
	double	theta_degree;

	center_to_point = v3_minus_v3(hit_info->point, sphere->pos);
	sphere->x_axis = v3_unit(
			v3_cross_product_ds(sphere->orientation, 0.0, -1.0, 0.0));
	y_axis = v3_cross_product_v3(sphere->orientation, sphere->x_axis);
	point = change_of_basis(
			center_to_point, sphere->x_axis, y_axis, sphere->orientation);
	get_sphere_phi_theta(&phi_degree, &theta_degree, point);
	return (get_sphere_checker_color(phi_degree, theta_degree, sphere));
}

void	get_sphere_phi_theta(double *phi, double *theta, t_vec3 point)
{
	*phi = get_sphere_phi(point) / M_PI * 180.0;
	*theta = get_sphere_theta(point) / M_PI * 180.0;
}

t_rgb	get_sphere_checker_color(double phi, double theta, t_sphere *sphere)
{
	double	unit_degree;
	t_rgb	color;

	unit_degree = 360.0 / sphere->texture.divid;
	if (phi < 0)
		phi -= unit_degree;
	if (theta < 0)
		theta -= unit_degree;
	if (((int)(phi / unit_degree)
		+ (int)(theta / unit_degree)) % 2 == 0)
		color = sphere->color;
	else
		v3_set(&color, 1.0, 1.0, 1.0);
	return (color);
}
