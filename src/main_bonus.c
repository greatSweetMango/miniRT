/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:04:49 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/31 15:26:40 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_scene(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win);
	exit(0);
}

void	init_img(t_scene *scene)
{
	t_img	img;

	img.img_ptr = mlx_new_image(scene->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data = (int *)mlx_get_data_addr(
			img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	scene->img = img;
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	scene->mlx = mlx_init();
	scene->win = mlx_new_window(
			scene->mlx, WIN_WIDTH + CONSOLE_WIDTH, WIN_HEIGHT, "miniRT");
	parse_arg(argc, argv, scene);
	normalize_camera(scene);
	init_img(scene);
	mlx_hook(scene->win, 2, 0, push_keys, scene);
	mlx_hook(scene->win, 17, 0, close_scene, scene);
	mlx_mouse_hook(scene->win, mouse_button, scene);
	draw_scene(scene);
	mlx_loop(scene->mlx);
	exit(0);
}
