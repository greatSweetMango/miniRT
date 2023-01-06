/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:04:49 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:41:54 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_all_objects_test(t_scene *scene)
{
	/* Test Code */
	printf("\n<ambient_lightning>\n\nr: %d\ng: %d\nb: %d\nratio: %f\n",
		scene->ambient_lightning.color.r,
		scene->ambient_lightning.color.g,
		scene->ambient_lightning.color.b,
		scene->ambient_lightning.ratio);

	printf("-END-\n<cameras>");
	t_list *cm_lst = scene->cameras;
	while (cm_lst)
	{
		t_camera *cm = (t_camera *)cm_lst->content;
		printf("\n\npos: %f %f %f\norientation: %f %f %f\nfov: %f",
			cm->pos.x,
			cm->pos.y,
			cm->pos.z,
			cm->orientation.x,
			cm->orientation.y,
			cm->orientation.z,
			cm->fov
			);
		cm_lst = cm_lst->next;
	}

	printf("\n-END-\n\n<lights>");
	t_list *lights_lst = scene->lights;
	while (lights_lst)
	{
		t_light	*light = (t_light *)lights_lst->content;

		printf("\n\npos: %f %f %f\nratio: %f\ncolor: %d %d %d",
			light->pos.x,
			light->pos.y,
			light->pos.z,
			light->ratio,
			light->color.r,
			light->color.g,
			light->color.b
			);
		lights_lst = lights_lst->next;
	}

	printf("\n-END-\n\n<spheres>");
	t_list *spheres_lst = scene->spheres;
	while (spheres_lst)
	{
		t_sphere	*sphere = (t_sphere *)spheres_lst->content;

		printf("\n\npos: %f %f %f\ndiameter: %f\ncolor: %d %d %d",
			sphere->pos.x,
			sphere->pos.y,
			sphere->pos.z,
			sphere->diameter,
			sphere->color.r,
			sphere->color.g,
			sphere->color.b
			);
		spheres_lst = spheres_lst->next;
	}

	printf("\n-END-\n\n<planes>");
	t_list *planes_lst = scene->planes;
	while (planes_lst)
	{
		t_plane	*plane = (t_plane *)planes_lst->content;

		printf("\n\npos: %f %f %f\norientation: %f %f %f\ncolor: %d %d %d",
			plane->pos.x,
			plane->pos.y,
			plane->pos.z,
			plane->orientation.x,
			plane->orientation.y,
			plane->orientation.z,
			plane->color.r,
			plane->color.g,
			plane->color.b
			);
		planes_lst = planes_lst->next;
	}

	printf("\n-END-\n\n<cylinders>");
	t_list *cylinders_lst = scene->cylinders;
	while (cylinders_lst)
	{
		t_cylinder	*cylinder = (t_cylinder *)cylinders_lst->content;

		printf("\n\npos: %f %f %f\norientation: %f %f %f\ndiameter: %f\nheight: %f\ncolor: %d %d %d",
			cylinder->pos.x,
			cylinder->pos.y,
			cylinder->pos.z,
			cylinder->orientation.x,
			cylinder->orientation.y,
			cylinder->orientation.z,
			cylinder->diameter,
			cylinder->height,
			cylinder->color.r,
			cylinder->color.g,
			cylinder->color.b
			);
		cylinders_lst = cylinders_lst->next;
	}
	printf("\n-END-\n");
}//테스트코드

int main(int argc, char **argv)
{
	t_scene *scene;
	
	scene = parse_arg(argc, argv);
	print_all_objects_test(scene);
	exit(0);
}