/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:19:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:18:22 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_cylinders(t_scene *scene, char **object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3] || !object[4]
		|| !object[5] || object[6])
		puterr_exit("Parsing fail! (object's property is wrong)");
	cylinder->pos = ft_ato_vec3(object[1]);
	cylinder->orientation = ft_ato_vec3(object[2]);
	cylinder->diameter = ft_atod(object[3]);
	cylinder->height = ft_atod(object[4]);
	cylinder->color = ft_ato_rgb(object[5]);
	ft_lstadd_back(&(scene->cylinders), ft_lstnew(cylinder));
}

void	set_planes(t_scene *scene, char **object)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3] || object[4])
		puterr_exit("Parsing fail! (object's property is wrong)");
	plane->pos = ft_ato_vec3(object[1]);
	plane->orientation = ft_ato_vec3(object[2]);
	plane->color = ft_ato_rgb(object[3]);
	ft_lstadd_back(&(scene->planes), ft_lstnew(plane));
}
