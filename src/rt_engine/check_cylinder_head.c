/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:56 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 14:04:51 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	t_vec3		pos;
	t_cylinder	*cylinder;
	double		t1;
	double		t2;

	cylinder = (t_cylinder *)cy->content;
	pos = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, -0.5 * cylinder->height));
	t1 = check_disk(ray, pos,
			v3_mul_d(cylinder->orientation, -1.0), cylinder->diameter / 2.0);
	pos = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, 0.5 * cylinder->height));
	t2 = check_disk(ray, pos, cylinder->orientation, cylinder->diameter / 2.0);
	hit_info->obj = NULL;
	if (t1 > 0)
	{
		hit_info->obj = cy;
		hit_info->t = t1;
		hit_info->normal = v3_mul_d(cylinder->orientation, -1.0);
		hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, t1));
		hit_info->color = get_cylinder_body_color(cylinder,hit_info);
	}
	if (t2 > 0 && (t1 < 0 || t2 < t1))
	{
		hit_info->obj = cy;
		hit_info->t = t2;
		hit_info->normal = cylinder->orientation;
		hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, t2));
		hit_info->color = get_cylinder_body_color(cylinder,hit_info);
	}
}
