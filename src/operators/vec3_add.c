/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:32:44 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/18 19:42:18 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3	vec3_plus_vec3(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3	vec3_plus_doubles(t_vec3 v1, double x, double y, double z)
{
	v1.x += x;
	v1.y += y;
	v1.z += z;
	return (v1);
}

t_vec3	vec3_plus_double(t_vec3 v1, double d)
{
	v1.x += d;
	v1.y += d;
	v1.z += d;
	return (v1);
}