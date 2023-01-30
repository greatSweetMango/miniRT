/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:45:48 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/30 20:56:42 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_cylinder(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == KEY_LEFT)
		printf("*CYLINDER KEY_LEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("*CYLINDER KEY_RIGHT\n");
	else if (keycode == KEY_DOWN)
		printf("*CYLINDER KEY_DOWN\n");
	else if (keycode == KEY_UP)
		printf("*CYLINDER KEY_UP\n");
	else if (keycode == KEY_A)
		printf("*CYLINDER KEY_A\n");
	else if (keycode == KEY_D)
		printf("*CYLINDER KEY_D\n");
	else if (keycode == KEY_S)
		printf("*CYLINDER KEY_S\n");
	else if (keycode == KEY_W)
		printf("*CYLINDER KEY_W\n");
	else if (keycode == KEY_PREV)
		printf("*CYLINDER KEY_PREV\n");
	else if (keycode == KEY_NEXT)
		printf("*CYLINDER KEY_NEXT\n");
}
