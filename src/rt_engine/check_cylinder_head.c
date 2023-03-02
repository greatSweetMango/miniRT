/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:56 by gyim              #+#    #+#             */
/*   Updated: 2023/03/02 19:15:53 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	t_cylinder_var	variable;
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)cy->content;
	variable = get_cylinder_var(ray, cylinder);
	variable.t[0] = check_cylinder_head(ray, variable.p1,
			v3_mul_d(v3_unit(cylinder->orientation), -1.0),
			cylinder->diameter / 2.0);
	variable.t[1] = check_cylinder_head(ray, variable.p2,
			v3_unit(cylinder->orientation),
			cylinder->diameter / 2.0);
	if (variable.t[0] > 0)
	
}

double	check_cylinder_head(t_ray ray, t_vec3 pos, t_vec3 normal, double radius)
{
	double	t;
	t_vec3	hit_point;
	t_vec3	pos_to_hit;

	t = v3_inner_product_v3(v3_minus_v3(pos, ray.pos), normal);
	t /= v3_inner_product_v3(ray.orient, normal);

	if (t < 0)
		return (t);
	hit_point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, t));
	pos_to_hit = v3_minus_v3(hit_point, pos);
	if (v3_inner_product_v3(pos_to_hit, pos_to_hit) <= radius * radius)
		return (t);
	else
		return (-1.0);
}
