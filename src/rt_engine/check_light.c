/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:00 by gyim              #+#    #+#             */
/*   Updated: 2023/03/02 19:24:24 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	add_light(t_hit_info hit_info, t_list *lst_light, t_scene *scene)
{
	t_list	*curr_light;
	t_light *light;
	double	density;

	curr_light = lst_light;
	if (hit_info.obj != NULL
		&& (hit_info.obj->obj_type == SPHERE
			|| hit_info.obj->obj_type == PLANE))
	// if (hit_info.obj != NULL)
	{
		while (curr_light)
		{
			light = (t_light *)curr_light->content;
			density = get_light_ratio(hit_info,
					light, scene);
			hit_info.color = v3_plus_v3(hit_info.color,
				v3_mul_d(light->color, density * light->ratio));
			curr_light = curr_light->next;
		}
	}
	return (hit_info);
}

double	get_light_ratio(t_hit_info hit_info, t_light *light, t_scene *scene)
{
	double		ratio;
	t_ray		light_ray;
	t_hit_info	obstacle;

	light_ray.orient = v3_unit(v3_minus_v3(light->pos, hit_info.point));
	light_ray.pos = v3_plus_v3(hit_info.point, v3_mul_d(light_ray.orient, 0.05));
	obstacle = check_objects(light_ray, scene);
	ratio = -1;
	if (obstacle.obj == NULL || obstacle.t == 0)
		ratio = v3_inner_product_v3(hit_info.normal, light_ray.orient);
	if (ratio < 0)
		return (0.0);
	return (ratio);
}
