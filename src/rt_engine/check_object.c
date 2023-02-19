/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/02/19 15:35:55 by gyim             ###   ########seoul.kr  */
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
	return (target_object);
}
