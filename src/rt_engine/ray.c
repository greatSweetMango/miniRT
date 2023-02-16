/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/02/16 19:47:26 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// screenpoint == ray_dir_vector

t_rgb	raytracing(t_scene *scnen, int w, int h)
{
	t_vec3	dx;
	t_vec3	dy;
	t_vec3	temp;
	t_vec3	screen_point;
	t_rgb	black;

	black.r = 0.0;
	black.g = 0.0;
	black.b = 0.0;

	dx = v3_mul_d(scnen->screen.x_dir,
			tan(scnen->screen.theta * w / WIN_WIDTH
				- scnen->screen.theta / 2));
	dy = v3_mul_d(scnen->screen.y_dir,
			tan(scnen->screen.theta * h / WIN_HEIGHT
				- scnen->screen.theta / 2));
	// dy = v3_mul_d(dy, cos(scnen->screen.theta * h / WIN_HEIGHT
	// 			- scnen->screen.theta / 2));
	// temp = v3_plus_v3(dx, dy);
	temp = v3_plus_v3(scnen->screen.orient, dx);
	temp = v3_unit(temp);
	temp = v3_plus_v3(temp, dy);
	temp = v3_unit(temp);
	screen_point = v3_plus_v3(scnen->screen.orient, temp);
	if (check_sphere(screen_point, scnen->spheres->next->content))
		return (((t_sphere *)(scnen->spheres->next->content))->color);
	else if (check_sphere(screen_point, scnen->spheres->content))
		return (((t_sphere *)(scnen->spheres->content))->color);
	else
		return (black);
}

int	check_sphere(t_vec3	ray, t_sphere *sphere)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = v3_inner_product_v3(ray, ray);
	b = -2.0 * v3_inner_product_v3(ray, sphere->pos);
	c = v3_inner_product_v3(sphere->pos, sphere->pos)
		- pow(sphere->diameter / 2.0, 2);
	discriminant = pow(b, 2.0) - 4.0 * a * c;
	if (discriminant >= 0)
		return (1);
	else
		return (0);
}
