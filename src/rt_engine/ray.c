/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/02/17 16:53:50 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// screenpoint == ray_dir_vector

t_rgb	raytracing(t_scene *scnen, int w, int h)
{
	t_vec3	screen_point;
	t_rgb	black;
	double	dist;

	black.r = 0.2;
	black.g = 0.2;
	black.b = 0.2;
	screen_point = v3_plus_v3(scnen->screen.p1m,
			v3_mul_d(scnen->screen.qx, (double)(w - 1)));
	screen_point = v3_plus_v3(screen_point,
			v3_mul_d(scnen->screen.qy, (double)(h - 1)));
	screen_point = v3_unit(screen_point);
	dist = -1;
	if (check_sphere(screen_point, scnen->spheres->next->content) > 0)
		return (((t_sphere *)(scnen->spheres->next->content))->color);
	else if (check_sphere(screen_point, scnen->spheres->content) > 0)
		return (((t_sphere *)(scnen->spheres->content))->color);
	else
		return (black);
}
