/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:47:43 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/30 20:56:07 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_sphere(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == KEY_LEFT)
		printf("*SPHERE KEY_LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("*SPHERE KEY_RIGHT\n");
	else if (keycode == KEY_DOWN)
		printf("*SPHERE KEY_DOWN\n");
	else if (keycode == KEY_UP)
		printf("*SPHERE KEY_UP\n");
	else if (keycode == KEY_A)
		printf("*SPHERE KEY_A\n");
	else if (keycode == KEY_D)
		printf("*SPHERE KEY_D\n");
	else if (keycode == KEY_S)
		printf("*SPHERE KEY_S\n");
	else if (keycode == KEY_W)
		printf("*SPHERE KEY_W\n");
	else if (keycode == KEY_PREV)
		printf("*SPHERE KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*SPHERE KEY_NEXT\n");
}
