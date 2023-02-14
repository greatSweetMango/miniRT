/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:30:05 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/14 19:12:30 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_obj(int keycode, t_vec3 *pos, t_screen screen)
{
	if (keycode == KEY_A)
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.x_dir, -MOVE_RATIO));
	else if (keycode == KEY_D)
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.x_dir, MOVE_RATIO));
	else if (keycode == KEY_S)
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.orient, -MOVE_RATIO));
	else if (keycode == KEY_W)
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.orient, MOVE_RATIO));
	else if (keycode == KEY_F)
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.y_dir, -MOVE_RATIO));
	else if (keycode == KEY_R)
		*pos = v3_plus_v3(*pos, v3_mul_d(screen.y_dir, MOVE_RATIO));
}