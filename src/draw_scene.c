/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:24:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/07 18:08:11 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_console_bg(t_scene *scene)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*str;
	
	str = NULL;
	img = mlx_xpm_file_to_image(scene->mlx,
			"./console_bg.xpm", &img_width, &img_height);
	mlx_put_image_to_window(scene->mlx, scene->win, img, WIN_WIDTH, 0);
	if (scene->selected_obj->obj_type == CAMERA)
		str = ft_strdup("[ CAMERA ]");
	else if (scene->selected_obj->obj_type == SPHERE)
		str = ft_strdup("[ SPHERE ]");
	else if (scene->selected_obj->obj_type == PLANE)
		str = ft_strdup("[ PLANE ]");
	else if (scene->selected_obj->obj_type == CYLINDER)
		str = ft_strdup("[ CYLINDER ]");
	else if (scene->selected_obj->obj_type == CONE)
		str = ft_strdup("[ CONE ]");
	if (str)
		mlx_string_put (scene->mlx, scene->win, 750,
			350, 0xFFFFFF, str);
	free(str);
}

void	*put_scene_to_img_thread(void *argv)
{
	t_thread	*thread; 
	int			w;
	int			h;

	thread = (t_thread *)argv;
	h = HEIGHT_BLOCK * thread->thread_no;
	while (h < HEIGHT_BLOCK * (thread->thread_no + 1))
	{
		w = 0; 
		while (w < WIN_WIDTH)
		{
			thread->img->data[h * WIN_WIDTH + w]
				= rt_engine(thread->scene, w, h);
			w++;
		}
		h++;
	}

	return (NULL);
}


void	put_scene_to_img(t_scene *scene, t_img *img)
{
	t_thread	threads[NUM_THREAD];
	int			i;
	int			joinrv;

	i = 0;
	while (i < NUM_THREAD)
	{
		threads[i].scene = scene;
		threads[i].img = img;
		threads[i].thread_no = i;
		pthread_create(&threads[i].th, NULL,
			&put_scene_to_img_thread, (void *)&threads[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREAD)
	{
		pthread_join(threads[i].th, (void **)&joinrv);
		i++;
	}
}

// void	put_scene_to_img(t_scene *scene, t_img *img)
// {
// 	int	w;
// 	int	h;

// 	h = 0;
// 	while (h < WIN_HEIGHT)
// 	{
// 		w = 0; 
// 		while (w < WIN_WIDTH)
// 		{
// 			img->data[h * WIN_WIDTH + w] = rt_engine(scene, w, h);
// 			w++;
// 		}
// 		h++;
// 	}
// }

void	draw_scene(t_scene *scene)
{
	put_scene_to_img(scene, &scene->img);
	set_console_bg(scene);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img.img_ptr, 0, 0);
}
