/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:04:49 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/01 18:46:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_all_objects_test(t_scene *scene)
{
	/* Test Code */
	printf("\n<ambient_lightning>\n\nr: %f\ng: %f\nb: %f\nratio: %f\n",
		scene->ambient_lightning.color.r * 255,
		scene->ambient_lightning.color.g * 255,
		scene->ambient_lightning.color.b * 255,
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

		printf("\n\npos: %f %f %f\nratio: %f\ncolor: %f %f %f",
			light->pos.x,
			light->pos.y,
			light->pos.z,
			light->ratio,
			light->color.r * 255,
			light->color.g * 255,
			light->color.b * 255
			);
		lights_lst = lights_lst->next;
	}

	printf("\n-END-\n\n<spheres>");
	t_list *spheres_lst = scene->spheres;
	while (spheres_lst)
	{
		t_sphere	*sphere = (t_sphere *)spheres_lst->content;

		printf("\n\npos: %f %f %f\ndiameter: %f\ncolor: %f %f %f",
			sphere->pos.x,
			sphere->pos.y,
			sphere->pos.z,
			sphere->diameter,
			sphere->color.r * 255,
			sphere->color.g * 255,
			sphere->color.b * 255
			);
		spheres_lst = spheres_lst->next;
	}

	printf("\n-END-\n\n<planes>");
	t_list *planes_lst = scene->planes;
	while (planes_lst)
	{
		t_plane	*plane = (t_plane *)planes_lst->content;

		printf("\n\npos: %f %f %f\norientation: %f %f %f\ncolor: %f %f %f",
			plane->pos.x,
			plane->pos.y,
			plane->pos.z,
			plane->orientation.x,
			plane->orientation.y,
			plane->orientation.z,
			plane->color.r * 255,
			plane->color.g * 255,
			plane->color.b * 255
			);
		planes_lst = planes_lst->next;
	}

	printf("\n-END-\n\n<cylinders>");
	t_list *cylinders_lst = scene->cylinders;
	while (cylinders_lst)
	{
		t_cylinder	*cylinder = (t_cylinder *)cylinders_lst->content;

		printf("\n\npos: %f %f %f\norientation: %f %f %f\ndiameter: %f\nheight: %f\ncolor: %f %f %f",
			cylinder->pos.x,
			cylinder->pos.y,
			cylinder->pos.z,
			cylinder->orientation.x,
			cylinder->orientation.y,
			cylinder->orientation.z,
			cylinder->diameter,
			cylinder->height,
			cylinder->color.r * 255,
			cylinder->color.g * 255,
			cylinder->color.b * 255
			);
		cylinders_lst = cylinders_lst->next;
	}
	printf("\n-END-\n");
	printf("<SCREEN>\norient: %f %f %f\nupperleft: %f %f %f\nlowerright: %f %f %f\nx_dir: %f %f %f\ny_dir: %f %f %f\n",
		scene->screen.orient.x,
		scene->screen.orient.y,
		scene->screen.orient.z,
		scene->screen.upperleft.x,
		scene->screen.upperleft.y,
		scene->screen.upperleft.z,
		scene->screen.lowerright.x,
		scene->screen.lowerright.y,
		scene->screen.lowerright.z,
		scene->screen.x_dir.x,
		scene->screen.x_dir.y,
		scene->screen.x_dir.z,
		scene->screen.y_dir.x,
		scene->screen.y_dir.y,
		scene->screen.y_dir.z
		);
}//테스트코드

int	close_scene(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win);
	exit(0);
}

void	init_img(t_scene *scene)
{
	t_img	img;

	img.img_ptr = mlx_new_image(scene->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	scene->img = img;
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	
	scene = parse_arg(argc, argv);
	normalize_camera(scene);
	// print_all_objects_test(scene); //테스트 코드
	scene->mlx = mlx_init();
	scene->win = mlx_new_window(scene->mlx, WIN_WIDTH + CONSOLE_WIDTH, WIN_HEIGHT, "miniRT");
	init_img(scene);
	mlx_hook(scene->win, 2, 0, push_keys, scene);
	mlx_hook(scene->win, 17, 0, close_scene, scene);
	mlx_mouse_hook(scene->win, mouse_button, NULL);
	draw_scene(scene);
	mlx_loop(scene->mlx);
	exit(0);
}

// int	main(void)
// {
// 	t_vec3 v1;
// 	t_vec3 v2;
	
// 	v1.x = 1.5;
// 	v1.y = 1.5;
// 	v1.z = 1.5;

// 	v2 = v1;
// 	v1 = v3_div_d(v1, 0);
// 	printf("%f %f %f\n", v1.x, v1.y, v1.z);
// 	return (0);
// }