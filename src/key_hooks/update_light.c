/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:44:17 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/31 15:24:18 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_light(int keycode, t_scene *scene)
{
	t_light	*light;

	light = scene->selected_obj->content;
	if (keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_R || keycode == KEY_F)
		move_obj(keycode, &light->pos, scene->screen);
	else if (keycode == KEY_PREV && scene->selected_obj->pre)
		scene->selected_obj = scene->selected_obj->pre;
	else if (keycode == KEY_NEXT && scene->selected_obj->next)
		scene->selected_obj = scene->selected_obj->next;
}
