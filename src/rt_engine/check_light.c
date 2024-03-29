/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:00 by gyim              #+#    #+#             */
/*   Updated: 2023/03/28 10:23:39 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	add_light(t_hit_info hit_info, t_list *lst_light, t_scene *scene)
{
	t_list	*curr_light;
	t_light	*light;
	double	density;

	curr_light = lst_light;
	if (hit_info.obj != NULL)
	{
		while (curr_light)
		{
			light = (t_light *)curr_light->content;
			density = get_light_ratio(hit_info,
					light, scene);
			hit_info.color = v3_plus_v3(hit_info.color,
					v3_mul_d(light->color, density * light->ratio));
			if (specular_light(hit_info, light) >= 0.0 && density != 0.0)
				hit_info.color = v3_plus_v3(hit_info.color,
						v3_mul_d(light->color, light->ratio
							* pow(specular_light(hit_info, light), 2.0)));
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
	light_ray.pos = v3_plus_v3(hit_info.point,
			v3_mul_d(hit_info.normal, 0.000001));
	obstacle = check_objects(light_ray, scene);
	ratio = v3_inner_product_v3(hit_info.normal, light_ray.orient);
	if (ratio < 0 || (obstacle.obj != NULL
			&& (get_distance(hit_info.point, light->pos)
				> get_distance(hit_info.point, obstacle.point))))
		ratio = 0.0;
	if (ratio < 0.0 && hit_info.obj->obj_type == PLANE)
		ratio = v3_inner_product_v3(
				v3_mul_d(hit_info.normal, -1.0), light_ray.orient);
	else
		return (ratio);
	if (ratio < 0)
		ratio = 0.0;
	return (ratio);
}

double	specular_light(t_hit_info hit_info, t_light *light)
{
	t_vec3	point_to_light;
	t_vec3	point_to_eye;
	t_vec3	reflect_light;

	point_to_light = v3_unit(v3_minus_v3(light->pos, hit_info.point));
	point_to_eye = v3_mul_d(hit_info.ray.orient, -1.0);
	reflect_light = v3_mul_d(hit_info.normal,
			2.0 * v3_inner_product_v3(hit_info.normal, point_to_light));
	reflect_light = v3_minus_v3(reflect_light, point_to_light);
	return (v3_inner_product_v3(v3_unit(reflect_light), v3_unit(point_to_eye)));
}

double	get_distance(t_vec3 p1, t_vec3 p2)
{
	t_vec3	temp;
	double	square;

	temp = v3_minus_v3(p1, p2);
	square = v3_inner_product_v3(temp, temp);
	return (sqrt(square));
}
