/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:12 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/24 17:46:37 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_sphere(int keycode, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = scene->selected_obj->content;
	if (keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_R || keycode == KEY_F)
		move_obj(keycode, &sphere->pos, scene->screen);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
		rotate_obj(keycode, &sphere->orientation, scene);
	else if (keycode == KEY_PREV && scene->selected_obj->pre)
		scene->selected_obj = scene->selected_obj->pre;
	else if (keycode == KEY_NEXT && scene->selected_obj->next)
		scene->selected_obj = scene->selected_obj->next;
	else if (keycode == KEY_DIAMETER_DOWN)
		sphere->diameter -= (double)RESIZE_RATIO;
	else if (keycode == KEY_DIAMETER_UP)
		sphere->diameter += (double)RESIZE_RATIO;
}
