/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/02/27 20:00:30 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_objects(t_ray ray, t_scene *scene)
{
	t_hit_info	target_object;
	t_hit_info	temp;

	target_object.obj = NULL;
	target_object = check_all_sphere(ray, scene->spheres);
	temp = check_all_plane(ray, scene->planes);
	if (target_object.obj == NULL
		|| (temp.obj != NULL && temp.t < target_object.t))
		target_object = temp;
	temp = check_all_cylinder(ray, scene->cylinders);
	if (target_object.obj == NULL
		|| (temp.obj != NULL && temp.t < target_object.t))
		target_object = temp;
	target_object.color = add_ambient_light(target_object.color, scene->ambient_lightning);
	return (target_object);
}
