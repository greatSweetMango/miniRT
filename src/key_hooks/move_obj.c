/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:30:05 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/31 20:19:55 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_obj(int keycode, t_vec3 *pos, t_screen screen)
{
	if (keycode == KEY_A)
	{
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.x_dir, -1));
		printf("KEY_A\n");
	}
	else if (keycode == KEY_D)
	{
		*pos = v3_plus_v3(*pos, screen.x_dir);
		printf("KEY_D\n");
	}
	else if (keycode == KEY_S)
	{
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.orient, -1));
		printf("KEY_S\n");
	}
	else if (keycode == KEY_W)
	{
		*pos = v3_plus_v3(*pos, screen.orient);
		printf("KEY_W\n");
	}
	else if (keycode == KEY_F)
	{
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.y_dir, -1));
		printf("KEY_F\n");
	}
	else if (keycode == KEY_R)
	{
		*pos = v3_plus_v3(*pos, screen.y_dir);
		printf("KEY_R\n");
	}

	printf("POS: %f %f %f\n", pos->x, pos->y, pos->z);
}