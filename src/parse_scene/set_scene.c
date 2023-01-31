/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:19:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/19 20:15:46 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_spheres(t_scene *scene, char **object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3] || object[4])
		puterr_exit("Parsing fail! (object's property is wrong)");
	sphere->pos = ft_ato_vec3(object[1]);
	sphere->diameter = ft_atod(object[2]);
	sphere->color = ft_ato_rgb(object[3]);
	ft_lstadd_back(&(scene->spheres), ft_lstnew(sphere, SPHERE));
}

void	set_lights(t_scene *scene, char **object)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3] || object[4])
		puterr_exit("Parsing fail! (object's property is wrong)");
	light->pos = ft_ato_vec3(object[1]);
	light->ratio = ft_atod(object[2]);
	light->color = ft_ato_rgb(object[3]);
	ft_lstadd_back(&(scene->lights), ft_lstnew(light, LIGHT));
}

void	set_cameras(t_scene *scene, char **object)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		puterr_exit("Allocate fail!\n");
	if (!object[1] || !object[2] || !object[3] || object[4])
		puterr_exit("Parsing fail! (object's property is wrong)");
	camera->pos = ft_ato_vec3(object[1]);
	camera->orientation = ft_ato_vec3(object[2]);
	camera->fov = ft_atod(object[3]);
	ft_lstadd_back(&(scene->cameras), ft_lstnew(camera, CAMERA));
}

void	set_ambient_lightning(t_scene *scene, char **object)
{
	if (!object[1] || !object[2] || object[3])
		puterr_exit("Parsing fail! (object's property is wrong)");
	scene->ambient_lightning.ratio = ft_atod(object[1]);
	scene->ambient_lightning.color = ft_ato_rgb(object[2]);
}

void	set_scene(t_scene *scene, char **object)
{
	if (!ft_strncmp("A", object[0], 3))
		set_ambient_lightning(scene, object);
	else if (!ft_strncmp("C", object[0], 3))
		set_cameras(scene, object);
	else if (!ft_strncmp("L", object[0], 3))
		set_lights(scene, object);
	else if (!ft_strncmp("sp", object[0], 3))
		set_spheres(scene, object);
	else if (!ft_strncmp("pl", object[0], 3))
		set_planes(scene, object);
	else if (!ft_strncmp("cy", object[0], 3))
		set_cylinders(scene, object);
	else
		puterr_exit("Parsing fail! (object name is wrong)");
}