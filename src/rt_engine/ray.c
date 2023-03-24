/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/03/24 15:52:29 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	get_ray_camera_to_obj(t_scene *scene, int w, int h)
{
	t_ray		ray;
	t_camera	*camera;

	camera = scene->cameras->content;
	ray.pos = camera->pos;
	ray.orient = v3_plus_v3(scene->screen.p1m,
			v3_mul_d(scene->screen.x_dir, (double)(w)));
	ray.orient = v3_plus_v3(ray.orient,
			v3_mul_d(scene->screen.y_dir, (double)(h)));
	ray.orient = v3_unit(ray.orient);
	return (ray);
}
