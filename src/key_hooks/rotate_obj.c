/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:18:38 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/19 11:28:48 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//라디안??
void	rotate_by_x_axis(t_vec3 *ori, double radian)
{
	ori->y = (cos(radian) * ori->y) - (sin(radian) * ori->z);
	ori->z = (sin(radian) * ori->y) + (cos(radian) * ori->z);
}

void	rotate_by_y_axis(t_vec3 *ori, double radian)
{
	ori->x = (cos(radian) * ori->x) - (sin(radian) * ori->z);
	ori->z = (sin(radian) * ori->x) + (cos(radian) * ori->z);
}

void	rotate_obj(int keycode, t_vec3 *orientation)
{
	double	radian;

	if (keycode == KEY_RIGHT || keycode == KEY_UP)
		radian = ROTATE_RATIO * PI / 180;
	else
		radian = ROTATE_RATIO * PI / 180 * -1;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		rotate_by_x_axis(orientation, radian);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_by_y_axis(orientation, radian);
}