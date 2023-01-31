/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:25:12 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/31 19:04:47 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_sphere(int keycode, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = scene->selected_obj->content;
	if (keycode == KEY_LEFT)
		printf("*SPHERE KEY_LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("*SPHERE KEY_RIGHT\n");
	else if (keycode == KEY_DOWN)
		printf("*SPHERE KEY_DOWN\n");
	else if (keycode == KEY_UP)
		printf("*SPHERE KEY_UP\n");
	else if (keycode == KEY_A || keycode == KEY_D
				|| keycode == KEY_W || keycode == KEY_S
				|| keycode == KEY_R || keycode == KEY_F)
	{
		printf("SPHERE ");
		move_obj(keycode, &sphere->pos, scene->screen);
	}
	else if (keycode == KEY_PREV)
		printf("*SPHERE KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*SPHERE KEY_NEXT\n");
}
