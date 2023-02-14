/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:24:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/14 19:55:04 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_scene_to_img(t_scene *scene, t_img *img)
{
	int	w;
	int	h;

	h = 0;
	while (h < WIN_HEIGHT)
	{
		w = 0; 
		while (w < WIN_WIDTH)
		{
			img->data[h * WIN_WIDTH + w] = rt_engine(scene, w, h);
			w++;
		}
		h++;
	}
}

void	draw_scene(t_scene *scene)
{
	put_scene_to_img(scene, &scene->img);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img.img_ptr, 0, 0);
}
