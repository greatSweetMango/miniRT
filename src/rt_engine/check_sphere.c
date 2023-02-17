/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/02/17 19:51:52 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_sphere(t_vec3	ray_orient, t_sphere *sphere)
{
	t_hit_info	hit_info;
	double		discriminant;
	t_vec3		v;
	double		t1;
	double		t2;

	v = v3_mul_d(sphere->pos, -1.0);
	discriminant = pow(v3_inner_product_v3(v, ray_orient), 2.0);
	discriminant -= ((v3_inner_product_v3(v, v)
				- pow(sphere->diameter / 2, 2.0)));
	t1 = -v3_inner_product_v3(v, ray_orient) + sqrt(discriminant);
	t2 = -v3_inner_product_v3(v, ray_orient) - sqrt(discriminant);
	hit_info.t = find_t(t1, t2);
	if (discriminant < 0 || hit_info.t < 0)
	{
		hit_info.obj = NULL;
		return (hit_info);
	}
	hit_info.obj = sphere;
	hit_info.point = v3_mul_d(ray_orient, hit_info.t);
	hit_info.color = sphere->color;
	return (hit_info);
}
