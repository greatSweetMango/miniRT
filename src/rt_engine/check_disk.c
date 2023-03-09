/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:05:10 by gyim              #+#    #+#             */
/*   Updated: 2023/03/09 13:14:04 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cone_bottom(t_hit_info *hit_info, t_ray ray, t_list *cone_list)
{
	t_cone		*cone;
	t_vec3		center;
	t_vec3		normal;
	double		t;

	hit_info->obj = NULL;
	hit_info->t = -1.0;
	hit_info->ray = ray;
	cone = (t_cone *)cone_list->content;
	normal = v3_mul_d(cone->orientation, -1.0);
	center = v3_plus_v3(cone->pos, v3_mul_d(normal, cone->height / 2.0));
	t = check_disk(ray, center, normal, cone->diameter / 2.0);
	if (t < 0)
		return ;
	hit_info->t = t;
	hit_info->normal = normal;
	hit_info->obj = cone_list;
	hit_info->point = v3_plus_v3(ray.pos,
			v3_mul_d(ray.orient, hit_info->t));
	hit_info->color = cone->color;
	hit_info->color = v3_mul_d(hit_info->color, 0.5);
	hit_info->ray = ray;
}

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