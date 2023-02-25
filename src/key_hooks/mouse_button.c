/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:02:35 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/14 19:24:06 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_button(int btn, int x, int y, t_scene *scene)
{
	(void)btn, (void)x, (void)y, (void)scene;
	// t_ray		ray;
	// t_hit_info	hit_info;

	// ray = get_ray_camera_to_obj(scene, x, y);
	// check_objects(ray, scene);
	// if (hit_info.obj)
	// {
	// 	scene->selected_obj = hit_info.obj;
	// 	printf("\nBTN: %d\nPOS: (%d, %d)\nSelected_OBJ: %d\n", btn, x, y, scene->selected_obj->obj_type);
	// }
	return (0);
}
