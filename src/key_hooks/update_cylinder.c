/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:03 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/12 17:28:08 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_cylinder(int keycode, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = scene->selected_obj->content;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
	{
		rotate_obj(keycode, &cylinder->orientation, scene);
		rotate_obj(keycode, &cylinder->x_axis, scene);
	}
	else if (keycode == KEY_A || keycode == KEY_D
				|| keycode == KEY_W || keycode == KEY_S
				|| keycode == KEY_R || keycode == KEY_F)
		move_obj(keycode, &cylinder->pos, scene->screen);
	else if (keycode == KEY_PREV && scene->selected_obj->pre)
		scene->selected_obj = scene->selected_obj->pre;
	else if (keycode == KEY_NEXT && scene->selected_obj->next)
		scene->selected_obj = scene->selected_obj->next;
}
