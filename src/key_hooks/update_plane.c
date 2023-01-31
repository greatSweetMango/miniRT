/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:07 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/31 20:15:22 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_plane(int keycode, t_scene *scene)
{
	t_plane	*plane;

	plane = scene->selected_obj->content;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
	{
		printf("PLANE ");
		rotate_obj(keycode, &plane->orientation);
	}
	else if (keycode == KEY_A || keycode == KEY_D
				|| keycode == KEY_W || keycode == KEY_S
				|| keycode == KEY_R || keycode == KEY_F)
	{
		printf("PLANE ");
		move_obj(keycode, &plane->pos, scene->screen);
	}
	else if (keycode == KEY_PREV)
		printf("*PLANE KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*PLANE KEY_NEXT\n");
}
