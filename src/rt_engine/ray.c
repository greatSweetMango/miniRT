/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/02/22 09:34:32 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// screenpoint == ray_dir_vector

t_ray	get_ray_camera_to_obj(t_scene *scene, int w, int h)
{
	t_ray		ray;
	t_camera	*camera;

	camera = scene->cameras->content;
	ray.pos = camera->pos;
	ray.orient = v3_plus_v3(scene->screen.p1m,
			v3_mul_d(scene->screen.x_dir, (double)(w - 1)));
	ray.orient = v3_plus_v3(ray.orient,
			v3_mul_d(scene->screen.y_dir, (double)(h - 1)));
	ray.orient = v3_unit(ray.orient);
	return (ray);
}
