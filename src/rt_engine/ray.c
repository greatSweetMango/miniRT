/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/02/17 16:46:34 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// screenpoint == ray_dir_vector

t_rgb	raytracing(t_scene *scnen, int w, int h)
{
	t_vec3	screen_point;
	t_rgb	black;
	double	dist;
	black.r = 0.0;
	black.g = 0.0;
	black.b = 0.0;
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


double	check_sphere(t_vec3	ray, t_sphere *sphere)
{
	double	discriminant;
	t_vec3	v;
	double	t1;
	double	t2;
	double	our_t;

	v = v3_mul_d(sphere->pos, -1.0);
	discriminant = pow(v3_inner_product_v3(v, ray), 2.0);
	discriminant -= ((v3_inner_product_v3(v, v)
				- pow(sphere->diameter / 2, 2.0)));
	if (discriminant < 0)
		return (0);	
	t1 = -v3_inner_product_v3(v, ray) + sqrt(discriminant);
	t2 = -v3_inner_product_v3(v, ray) - sqrt(discriminant);
	our_t = find_t(t1, t2);
	if (our_t < 0)
		return (0);
	else
		return (1);
	return (1);
}
