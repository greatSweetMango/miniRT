/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:24:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/17 20:01:20 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_scene_to_img(t_scene *scene, t_img *img)
{
	int	w;
	int	h;
	
    t_rgb   rgb;
    (void)scene;////////////////
	h = 0;
    while (h < WIN_HEIGHT)
    {
        w = 0; 
        while (w < WIN_WIDTH)
        {
            rgb.r = (double)w / 255;
            rgb.g = (double)h / 255;
            rgb.b = 0.25;
            img->data[h * WIN_WIDTH + w] = ft_rgb_to_i(rgb);//rt_engine(scene);// 레이트레이싱 엔진 추가필요
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