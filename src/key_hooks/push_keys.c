/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:19 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/02 16:14:27 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	push_keys(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
		close_scene(scene);
	if (keycode == KEY_SPACEBAR)
		scene->selected_obj = scene->cameras;
	if (scene->selected_obj->obj_type == CAMERA)
		update_camera(keycode, scene);
	else if (scene->selected_obj->obj_type == SPHERE)
		update_sphere(keycode, scene);
	else if (scene->selected_obj->obj_type == PLANE)
		update_plane(keycode, scene);
	else if (scene->selected_obj->obj_type == CYLINDER)
		update_cylinder(keycode, scene);
	
	printf("KEYCODE: %d\n", keycode);
	printf("SELECTED OBJ: %d\n\n", scene->selected_obj->obj_type);
	draw_scene(scene);
	return (0);
}
