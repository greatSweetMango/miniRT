/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:03 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/31 20:15:17 by jaehyuki         ###   ########.fr       */
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
		printf("CYLINDER ");
		rotate_obj(keycode, &cylinder->orientation);
	}
	else if (keycode == KEY_A || keycode == KEY_D
				|| keycode == KEY_W || keycode == KEY_S
				|| keycode == KEY_R || keycode == KEY_F)
	{
		printf("CYLINDER ");
		move_obj(keycode, &cylinder->pos, scene->screen);
	}
	else if (keycode == KEY_PREV)
		printf("*CYLINDER KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*CYLINDER KEY_NEXT\n");
}
