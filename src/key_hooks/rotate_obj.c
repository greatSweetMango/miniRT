/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:06 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/24 17:09:50 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_quaternion	get_quaternion_from_axis_angle(t_vec3 axis, double angle)
{
	t_quaternion	q;
	double			half_angle;
	double			sin_half_angle;

	half_angle = angle / 2.0;
	sin_half_angle = sin(half_angle);
	q.w = cos(half_angle);
	q.x = axis.x * sin_half_angle;
	q.y = axis.y * sin_half_angle;
	q.z = axis.z * sin_half_angle;
	return (q);
}

t_quaternion	multiply_quaternion(t_quaternion a, t_quaternion b)
{
	t_quaternion	q;

	q.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	q.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	q.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	q.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	return (q);
}

t_quaternion	get_quaternion_conjugate(t_quaternion q)
{
	t_quaternion	conj;

	conj.w = q.w;
	conj.x = -q.x;
	conj.y = -q.y;
	conj.z = -q.z;
	return (conj);
}

t_vec3	quaternion_rotate(t_vec3 orient, t_vec3 axis, double angle)
{
	t_quaternion	q;
	t_quaternion	p;
	t_quaternion	conj_q;
	t_vec3			ret;

	q = get_quaternion_from_axis_angle(axis, angle);
	p.w = 0;
	p.x = orient.x;
	p.y = orient.y;
	p.z = orient.z;
	conj_q = get_quaternion_conjugate(q);
	p = multiply_quaternion(q, multiply_quaternion(p, conj_q));
	v3_set(&ret, p.x, p.y, p.z);
	return (ret);
}

void	rotate_obj(int keycode, t_vec3 *orientation, t_scene *scene)
{
	double	angle;
	t_vec3	y_axis;
	t_vec3	dx_axis;

	dx_axis = v3_unit(scene->screen.x_dir);
	v3_set(&y_axis, 0, 1, 0);
	if (keycode == KEY_RIGHT || keycode == KEY_UP)
		angle = M_PI / -ROTATE_RATIO;
	else
		angle = M_PI / ROTATE_RATIO;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		*orientation = quaternion_rotate(*orientation, dx_axis, -angle);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		*orientation = quaternion_rotate(*orientation, y_axis, angle);
}
