/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:18:26 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/23 15:38:52 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	switch_camera(int keycode, t_scene *scene)
{
	if (keycode == KEY_PREV && scene->cameras->pre)
	{
		scene->cameras = scene->cameras->pre;
		scene->selected_obj = scene->cameras;
	}
	else if (keycode == KEY_NEXT && scene->cameras->next)
	{
		scene->cameras = scene->cameras->next;
		scene->selected_obj = scene->cameras;
	}
}

void	update_camera(int keycode, t_scene *scene)
{
	t_camera	*camera;

	camera = scene->selected_obj->content;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
		rotate_obj(keycode, &camera->orientation, scene);
	else if (keycode == KEY_A || keycode == KEY_D
			|| keycode == KEY_W || keycode == KEY_S
			|| keycode == KEY_R || keycode == KEY_F)
		move_obj(keycode, &camera->pos, scene->screen);
	else if (keycode == KEY_PREV || keycode == KEY_NEXT)
		switch_camera(keycode, scene);
	normalize_camera(scene);
}
