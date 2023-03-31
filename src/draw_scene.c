/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:24:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/31 16:01:16 by jaehyuki         ###   ########.fr       */
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
	ft_file_check("./console_bg.xpm");
	img = mlx_xpm_file_to_image(scene->mlx,
			"./console_bg.xpm", &img_width, &img_height);
	mlx_put_image_to_window(scene->mlx, scene->win, img, WIN_WIDTH, 0);
	if (scene->selected_obj->obj_type == CAMERA)
		str = ft_strdup("[ CAMERA ]");
	else if (scene->selected_obj->obj_type == LIGHT)
		str = ft_strdup("[ LIGHT ]");
	else if (scene->selected_obj->obj_type == SPHERE)
		str = ft_strdup("[ SPHERE ]");
	else if (scene->selected_obj->obj_type == PLANE)
		str = ft_strdup("[ PLANE ]");
	else if (scene->selected_obj->obj_type == CYLINDER)
		str = ft_strdup("[ CYLINDER ]");
	else if (scene->selected_obj->obj_type == CONE)
		str = ft_strdup("[ CONE ]");
	if (str)
		mlx_string_put(scene->mlx, scene->win, 750, 350, 0xFFFFFF, str);
	free(str);
}

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
	set_console_bg(scene);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img.img_ptr, 0, 0);
}
