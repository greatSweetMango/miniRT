/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:18:26 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/30 20:57:00 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_camera(int keycode, t_scene *scene)
{	
	(void)scene;
	if (keycode == KEY_LEFT)
		printf("*CAMERA KEY_LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("*CAMERA KEY_RIGHT\n");
	else if (keycode == KEY_DOWN)
		printf("*CAMERA KEY_DOWN\n");
	else if (keycode == KEY_UP)
		printf("*CAMERA KEY_UP\n");
	else if (keycode == KEY_A)
		printf("*CAMERA KEY_A\n");
	else if (keycode == KEY_D)
		printf("*CAMERA KEY_D\n");
	else if (keycode == KEY_S)
		printf("*CAMERA KEY_S\n");
	else if (keycode == KEY_W)
		printf("*CAMERA KEY_W\n");
	else if (keycode == KEY_PREV)
		printf("*CAMERA KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*CAMERA KEY_NEXT\n");
}
