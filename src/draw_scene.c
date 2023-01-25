/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:24:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/25 19:43:41 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	put_scene_to_img(t_scene *scene, t_img *img)
// {
// 	int	w;
// 	int	h;
	
// 	t_rgb   rgb;
// 	(void)scene;////////////////
// 	h = 0;
// 	while (h < WIN_HEIGHT)
// 	{
// 		w = 0; 
// 		while (w < WIN_WIDTH)
// 		{
// 			rgb.r = (double)w / 255;
// 			rgb.g = (double)h / 255;
// 			rgb.b = 0.25;
// 				img->data[h * WIN_WIDTH + w] = ft_rgb_to_i(rgb);//rt_engine(scene);// 레이트레이싱 엔진 추가필요
// 			w++;
// 		}
// 		h++;
// 	}
// }

void	put_scene_to_img(t_scene *scene, t_img *img)
{
	t_vec3		offset;
	t_camera	*camera;
	t_sphere	*sphere;
	t_screen	screen;

	img = NULL;
	camera = (t_camera *)scene->cameras->content;
	sphere = (t_sphere *)scene->spheres->content;
	offset = v3_mul_d(camera->pos, -1);
	sphere->pos = v3_plus_v3(sphere->pos, offset);
	set_screen(&screen, camera);
	raytracing(scene, &screen, img);
}

void	draw_scene(t_scene *scene)
{
	put_scene_to_img(scene, &scene->img);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img.img_ptr, 0, 0);
}

