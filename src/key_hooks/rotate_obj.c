/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:18:38 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/14 09:44:05 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void get_rotation_matrix(float matrix[3][3], t_vec3 axis_norm, float theta)
{
	float x;
	float y;
	float z;

	x = axis_norm.x;
	y = axis_norm.y;
	z = axis_norm.z;
	matrix[0][0] = cos(theta) + x * x * (1 - cos(theta));
    matrix[0][1] = x * y * (1 - cos(theta)) - z * sin(theta);
    matrix[0][2] = x * z * (1 - cos(theta)) + y * sin(theta);
    matrix[1][0] = x * y * (1 - cos(theta)) + z * sin(theta);
    matrix[1][1] = cos(theta) + y * y * (1 - cos(theta));
    matrix[1][2] = y * z * (1 - cos(theta)) - x * sin(theta);
    matrix[2][0] = x * z * (1 - cos(theta)) - y * sin(theta);
    matrix[2][1] = y * z * (1 - cos(theta)) + x * sin(theta);
    matrix[2][2] = cos(theta) + z * z * (1 - cos(theta));
}

t_vec3	rotate_by_dx_axis(t_vec3 orient, t_vec3 axis, double angle)
{
    // float rotation_matrix[3][3];
	// t_vec3	result;

    // get_rotation_matrix(rotation_matrix, vec3_normalize(axis), angle * PI / 180);
	// v3_set(&result, rotation_matrix[0][0] * orient.x + rotation_matrix[0][1] * orient.y + rotation_matrix[0][2] * orient.z,
	// 	rotation_matrix[1][0] * orient.x + rotation_matrix[1][1] * orient.y + rotation_matrix[1][2] * orient.z,
	// 	rotation_matrix[2][0] * orient.x + rotation_matrix[2][1] * orient.y + rotation_matrix[2][2] * orient.z);

	t_vec3	result;
	t_vec3	u;
	t_vec3	v;
	t_vec3	v_axis;

	u = v3_mul_d(v3_unit(orient), cos(angle));
	v_axis = v3_unit(v3_cross_product_v3(axis, orient));
	// printf("v_axis : %f %f %f\n", v_axis.x, v_axis.y, v_axis.z);
	v = v3_mul_d(v_axis, sin(angle));
	// printf("u : %f %f %f\n", u.x, u.y, u.z);
	// printf("v : %f %f %f\n", v.x, v.y, v.z);
	result = v3_unit(v3_plus_v3(u, v));
	printf("after rotate : %f %f %f\n", result.x, result.y, result.z);
	return (result);
}

void	rotate_by_y_axis(t_vec3 *ori, double theta)
{
	ori->x = (cos(theta) * ori->x) - (sin(theta) * ori->z);
	ori->z = (sin(theta) * ori->x) + (cos(theta) * ori->z);
}

void	rotate_obj(int keycode, t_vec3 *orientation, t_scene *scene)
{
	double	angle;

	if (keycode == KEY_RIGHT || keycode == KEY_UP)
		angle = ROTATE_RATIO / 180.0 * M_PI;
	else
		angle = -ROTATE_RATIO / 180.0 * M_PI;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		*orientation = rotate_by_dx_axis(*orientation, scene->screen.x_dir, angle);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		// rotate_by_y_axis(orientation, angle);`
		*orientation = rotate_by_dx_axis(*orientation, scene->screen.y_dir, angle);
	printf("ORIENT : %f %f %f\n", orientation->x, orientation->y, orientation->z);
}