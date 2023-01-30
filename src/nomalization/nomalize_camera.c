/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomalize_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:31:15 by gyim              #+#    #+#             */
/*   Updated: 2023/01/30 19:19:33 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_spheres_pos(t_list *spheres, t_camera *now_cam)
{
	t_sphere	*sphere;

	while (spheres)
	{
		sphere = spheres->content;
		sphere->pos = v3_minus_v3(sphere->pos, now_cam->pos);
		spheres = spheres->next;
	}
}

void	set_lights_pos(t_list *lights, t_camera *now_cam)
{
	t_light	*light;

	while (lights)
	{
		light = lights->content;
		light->pos = v3_minus_v3(light->pos, now_cam->pos);
		lights = lights->next;
	}
}

void	set_cameras_pos(t_list *cameras, t_camera *now_cam)
{
	t_camera *cam;

	cameras = ft_lstlast(cameras);
	while (cameras)
	{
		if (cameras->content != now_cam)
		{
			cam = cameras->content;
			cam->pos = v3_minus_v3(cam->pos, now_cam->pos);
		}
		cameras = cameras->pre;
	}
}

t_screen	get_screen(t_camera *camera)
{
	t_screen	screen;
	
	screen.orient = v3_unit(camera->orientation);
	screen.x_dir = v3_cross_product_ds(screen.orient, 0, 1, 0);
	screen.y_dir = v3_cross_product_v3(screen.x_dir, screen.orient);
	screen.lowerleft = v3_minus_v3(screen.orient, v3_plus_v3(screen.x_dir, screen.y_dir));
	screen.upperright = v3_plus_v3(screen.orient, v3_plus_v3(screen.x_dir, screen.y_dir));
	return (screen);
}

void	nomalize_camera(t_scene *scene)
{
	t_camera	*now_cam;

	now_cam = scene->cameras->content;
	set_cameras_pos(scene->cameras, now_cam);
	set_lights_pos(scene->lights, now_cam);
	set_spheres_pos(scene->spheres, now_cam);
	set_planes_pos(scene->planes, now_cam);
	set_cylinders_pos(scene->cylinders, now_cam);
	scene->screen = get_screen(now_cam);
}
