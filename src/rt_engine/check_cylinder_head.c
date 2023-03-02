/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:56 by gyim              #+#    #+#             */
/*   Updated: 2023/03/02 16:11:46 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	t_cylinder_var	variable;
	t_cylinder		*cylinder;
	double			t[2];

	hit_info->obj = NULL;
	cylinder = (t_cylinder *)cy->content;
	variable = get_cylinder_var(ray, cylinder);
	t[0] = check_cylinder_head(ray, variable.p1,
			v3_mul_d(v3_unit(cylinder->orientation), -1), cylinder->diameter / 2);
	t[1] = check_cylinder_head(ray, variable.p2,
			v3_unit(cylinder->orientation), cylinder->diameter / 2);
	hit_info->t = find_t(t[0], t[1]);
	if (hit_info->t < 0)
		return ;
	hit_info->normal = v3_unit(cylinder->orientation);
	hit_info->obj = cy;
	hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info->t));
	hit_info->color = cylinder->color;
}

double	check_cylinder_head(t_ray ray, t_vec3 pos, t_vec3 normal, double radius)
{
	double	t;
	double	dist;
	t_vec3	p0p1;
	t_vec3	hit_v;

	p0p1 = v3_minus_v3(ray.pos, pos);
	t = v3_inner_product_v3(p0p1, normal);
	t /= v3_inner_product_v3(ray.orient, normal);
	if (t < 0)
		return (t);
	hit_v = v3_plus_v3(p0p1, v3_mul_d(v3_unit(ray.orient), t));
	dist = v3_inner_product_v3(hit_v, hit_v);
	if (dist <= radius * radius)
		return (t);
	else
		return (-1.0);
}
