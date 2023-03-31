/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:19:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/31 16:04:56 by jaehyuki         ###   ########.fr       */
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
		|| !object[5])
		puterr_exit("Parsing fail! (object's property is wrong)");
	cylinder->pos = ft_ato_vec3(object[1]);
	cylinder->orientation = ft_ato_vec3(object[2]);
	cylinder->orientation = v3_unit(cylinder->orientation);
	cylinder->diameter = ft_atod(object[3]);
	cylinder->height = ft_atod(object[4]);
	cylinder->color = ft_ato_rgb(object[5]);
	cylinder->texture = get_texture(scene, &object[6], CYLINDER);
	ft_lstadd_back(&(scene->cylinders), ft_lstnew(cylinder, CYLINDER));
}

void	set_planes(t_scene *scene, char **object)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3])
		puterr_exit("Parsing fail! (object's property is wrong)");
	plane->pos = ft_ato_vec3(object[1]);
	plane->orientation = ft_ato_vec3(object[2]);
	plane->orientation = v3_unit(plane->orientation);
	if (plane->orientation.x == 0 && plane->orientation.y == 1.0
		&& plane->orientation.z == 0)
		v3_set(&plane->dx, 1, 0, 0);
	else
		plane->dx = v3_unit(
				v3_mul_d(v3_cross_product_ds(plane->orientation,
						0, 1, 0), -1));
	plane->dy = v3_unit(v3_cross_product_v3(plane->orientation, plane->dx));
	plane->color = ft_ato_rgb(object[3]);
	plane->texture = get_texture(scene, &object[4], PLANE);
	ft_lstadd_back(&(scene->planes), ft_lstnew(plane, PLANE));
}

void	set_cones(t_scene *scene, char **object)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3] || !object[4]
		|| !object[5] || object[6])
		puterr_exit("Parsing fail! (object's property is wrong)");
	cone->pos = ft_ato_vec3(object[1]);
	cone->orientation = ft_ato_vec3(object[2]);
	cone->orientation = v3_unit(cone->orientation);
	cone->diameter = ft_atod(object[3]);
	cone->height = ft_atod(object[4]);
	cone->color = ft_ato_rgb(object[5]);
	ft_lstadd_back(&(scene->cones), ft_lstnew(cone, CONE));
}
