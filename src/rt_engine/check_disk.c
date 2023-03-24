/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:05:10 by gyim              #+#    #+#             */
/*   Updated: 2023/03/24 19:47:10 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_disk(t_ray ray, t_vec3 pos, t_vec3 normal, double radius)
{
	double	t;
	t_vec3	hit_point;
	t_vec3	pos_to_hit;

	t = v3_inner_product_v3(v3_minus_v3(pos, ray.pos), normal);
	t /= v3_inner_product_v3(ray.orient, normal);
	if (t < 0)
		return (-1.0);
	hit_point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, t));
	pos_to_hit = v3_minus_v3(hit_point, pos);
	if (v3_inner_product_v3(pos_to_hit, pos_to_hit) <= radius * radius)
		return (t);
	else
		return (-1.0);
}
