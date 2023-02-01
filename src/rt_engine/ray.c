/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/02/01 19:52:47 by gyim             ###   ########seoul.kr  */
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

	dx = v3_div_d(scnen->screen.x_dir , (WIN_WIDTH / 2.0));
	dy = v3_div_d(scnen->screen.y_dir , (WIN_HEIGHT / 2.0));
	dx = v3_mul_d(dx, (double)w);
	dy = v3_mul_d(dy, (double)h);
	temp = v3_plus_v3(scnen->screen.upperleft, dx);
	screen_point = v3_minus_v3(temp, dy);
	if (check_sphere(screen_point, scnen->spheres->content))
		return (((t_sphere *)(scnen->spheres->content))->color);
	else
		return (black);
}

int	check_sphere(t_vec3	ray, t_sphere *sphere)
{
	double	discriminant;
	double	term[2];

	term[0] = v3_inner_product_v3(ray, sphere->pos);
	term[0] = pow(term[0], 2.0);
	term[1] = v3_inner_product_v3(ray, ray);
	term[1] = term[1]
		* (v3_inner_product_v3(sphere->pos, sphere->pos)
			- pow(sphere->diameter / 2, 2.0));
	discriminant = term[0] - term[1];
	if (discriminant >= 0)
		return (1);
	else
		return (0);
}
