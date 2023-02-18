/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:43:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/18 18:38:44 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

	//get_screen(scene);
	//get_레이저 쏠 좌표(screen, w, h)
	//raytracing()
	//계산(scnen, 레이저 쏠 좌표)
int	rt_engine(t_scene *scene, int w, int h)
{
	t_ray		ray;
	t_hit_info	hit_info;

	normalize_camera(scene); //??필요한지?
	ray = get_ray_camera_to_obj(scene, w, h);
	hit_info = check_sphere(ray.orient, scene->spheres->content);
	if (hit_info.obj == NULL)
	{
		hit_info.color.r = 0.0;
		hit_info.color.g = 0.0;
		hit_info.color.b = 0.0;
	}
	return (ft_rgb_to_i(hit_info.color));
}
// t_rgb	raytracing(t_scene *scene, int w, int h)
// {
// }
	// if (check_sphere(screen_point, scene->spheres->next->content) > 0)
	// 	return (((t_sphere *)(scene->spheres->next->content))->color);
	// else if (check_sphere(screen_point, scene->spheres->content) > 0)
	// 	return (((t_sphere *)(scene->spheres->content))->color);
	// else
	// 	return (black);
