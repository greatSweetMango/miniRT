/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:47:03 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/30 20:56:27 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_plane(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == KEY_LEFT)
		printf("*PLANE KEY_LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("*PLANE KEY_RIGHT\n");
	else if (keycode == KEY_DOWN)
		printf("*PLANE KEY_DOWN\n");
	else if (keycode == KEY_UP)
		printf("*PLANE KEY_UP\n");
	else if (keycode == KEY_A)
		printf("*PLANE KEY_A\n");
	else if (keycode == KEY_D)
		printf("*PLANE KEY_D\n");
	else if (keycode == KEY_S)
		printf("*PLANE KEY_S\n");
	else if (keycode == KEY_W)
		printf("*PLANE KEY_W\n");
	else if (keycode == KEY_PREV)
		printf("*PLANE KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*PLANE KEY_NEXT\n");
}
