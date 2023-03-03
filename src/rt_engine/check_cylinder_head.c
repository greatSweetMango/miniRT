/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:56 by gyim              #+#    #+#             */
/*   Updated: 2023/03/03 19:20:24 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	t_cylinder_var	variable;
	t_cylinder		*cylinder;

	hit_info->obj = NULL;
	hit_info->t = -1.0;
	hit_info->ray = ray;
	cylinder = (t_cylinder *)cy->content;
	variable = get_cylinder_var(ray, cylinder);
	variable.t[0] = check_cylinder_head(ray, variable.p1,
			v3_mul_d(cylinder->orientation, -1.0),
			cylinder->diameter / 2.0);
	variable.t[1] = check_cylinder_head(ray, variable.p2,
			cylinder->orientation,
			cylinder->diameter / 2.0);
	if (variable.t[0] < 0 && variable.t[1] < 0)
		return ;
	if (variable.t[0] > 0)
	{
		hit_info->t = variable.t[0];
		hit_info->normal = v3_mul_d(v3_unit(cylinder->orientation), -1.0);
		hit_info->color = cylinder->color;
		hit_info->color.x *= 0.5;
		hit_info->color.y *= 0.5;
		hit_info->color.z *= 0.5;
	}
	if (variable.t[1] > 0 
		&& (variable.t[0] < 0 || variable.t[1] < variable.t[0]))
	{
		hit_info->t = variable.t[1];
		hit_info->normal = v3_unit(cylinder->orientation);
		hit_info->color = cylinder->color;
		hit_info->color.x = 1 - hit_info->color.x;
		hit_info->color.y = 1 - hit_info->color.x;
		hit_info->color.z = 1 - hit_info->color.x;
	}
	if (hit_info->t > 0)
	{
		hit_info->obj = cy;
		hit_info->point = v3_plus_v3(ray.pos,
				v3_mul_d(ray.orient, hit_info->t));
		// hit_info->color = cylinder->color;
		// hit_info->color.x *= 0.5;
		// hit_info->color.y *= 0.5;
		// hit_info->color.z *= 0.5;
	}
}

double	check_cylinder_head(t_ray ray, t_vec3 pos, t_vec3 normal, double radius)
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
