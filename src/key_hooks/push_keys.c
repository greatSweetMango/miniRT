/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:19 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/31 15:17:22 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	push_keys(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
		close_scene(scene);
	if (keycode == KEY_SPACEBAR)
		scene->selected_obj = scene->cameras;
	else if (keycode == KEY_LIGHT)
		scene->selected_obj = scene->lights;
	if (scene->selected_obj->obj_type == CAMERA)
		update_camera(keycode, scene);
	else if (scene->selected_obj->obj_type == LIGHT)
		update_light(keycode, scene);
	else if (scene->selected_obj->obj_type == SPHERE)
		update_sphere(keycode, scene);
	else if (scene->selected_obj->obj_type == PLANE)
		update_plane(keycode, scene);
	else if (scene->selected_obj->obj_type == CYLINDER)
		update_cylinder(keycode, scene);
	else if (scene->selected_obj->obj_type == CONE)
		update_cone(keycode, scene);
	draw_scene(scene);
	return (0);
}
