/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:54:56 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/01 18:47:51 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v3_div_v3(t_vec3 v1, t_vec3 v2)
{
	if (v2.x == 0 || v2.y == 0 || v2.z == 0)
		puterr_exit("v3_div_v3 : Divide with 0!\n");
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	return (v1);
}

t_vec3	v3_div_ds(t_vec3 v1, double x, double y, double z)
{
	if (x == 0 || y == 0 || z == 0)
		puterr_exit("v3_div_v3 : Divide with 0!\n");
	v1.x /= x;
	v1.y /= y;
	v1.z /= z;
	return (v1);
}

t_vec3	v3_div_d(t_vec3 v1, double d)
{
	if (d == 0)
		puterr_exit("v3_div_v3 : Divide with 0!\n");
	v1.x /= d;
	v1.y /= d;
	v1.z /= d;
	return (v1);
}
