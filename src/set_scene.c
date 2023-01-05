/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:19:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/05 17:24:50 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient_lightning(t_scene *scene, char **object)
{
	if (!scene[1] || !scene[2] || scene[3])
		puterr_exit("Parsing fail! (object's property is wrong)");
	scene->ambient_lightning.color = get_ratio(scene[1]);
	// scene->ambient_lightning.color = get_rgb(scene[2]);
	if (scene[3])
}

void	set_scene(t_scene *scene, char **object)
{
	if (ft_strncmp("A" , object[0], 3))
		set_ambient_lightning(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_cameras(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_lights(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_spheres(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_planes(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_squares(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_cylinders(scene, object);
	// else if (ft_strncmp("C" , object[0], 3))
	// 	set_triangles(scene, object);
	else
		puterr_exit("Parsing fail! (object name is wrong)");
}
