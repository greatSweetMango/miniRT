/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:02:35 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/06 17:59:55 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_button(int btn, int x, int y, t_scene *scene)
{
	t_ray		ray;
	t_hit_info	hit_info;

	(void)btn;
	ray = get_ray_camera_to_obj(scene, x, y);
	hit_info = check_objects(ray, scene);
	if (hit_info.obj)
		scene->selected_obj = hit_info.obj;
	return (0);
}
