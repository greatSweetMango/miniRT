/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:43:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/24 15:52:36 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_engine(t_scene *scene, int w, int h)
{
	t_ray		ray;
	t_hit_info	hit_info;

	ray = get_ray_camera_to_obj(scene, w, h);
	hit_info = check_objects(ray, scene);
	hit_info.color = add_ambient_light(hit_info.color,
			scene->ambient_lightning);
	hit_info = add_light(hit_info, scene->lights, scene);
	if (hit_info.obj == NULL)
	{
		hit_info.color.x = 0.0;
		hit_info.color.y = 0.0;
		hit_info.color.z = 0.0;
	}
	return (ft_rgb_to_i(hit_info.color));
}
