/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:56 by gyim              #+#    #+#             */
/*   Updated: 2023/03/31 15:18:56 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	t_cylinder	*cylinder;
	double		t1;
	double		t2;

	cylinder = (t_cylinder *)cy->content;
	t1 = get_cylinder_head_t(cylinder, ray,
			v3_mul_d(cylinder->orientation, -1.0));
	t2 = get_cylinder_head_t(cylinder, ray, cylinder->orientation);
	hit_info->obj = NULL;
	hit_info->color = cylinder->color;
	if (t1 > 0)
	{
		set_cylinder_head_hit_info(hit_info, cy, t1,
			v3_mul_d(cylinder->orientation, -1.0));
		hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, t1));
	}
	if (t2 > 0 && (t1 < 0 || t2 < t1))
	{
		set_cylinder_head_hit_info(hit_info, cy, t2,
			cylinder->orientation);
		hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, t2));
	}
	if (hit_info->obj != NULL)
		hit_info->color = get_cylinder_head_color(cylinder, hit_info);
}

double	get_cylinder_head_t(t_cylinder *cylinder, t_ray ray, t_vec3 orient)
{
	t_vec3	pos;

	pos = v3_plus_v3(cylinder->pos, v3_mul_d(orient, 0.5 * cylinder->height));
	return (check_disk(ray, pos, orient, cylinder->diameter / 2.0));
}

void	set_cylinder_head_hit_info(t_hit_info *hit_info, t_list *cy,
	double t, t_vec3 normal)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)cy->content;
	hit_info->obj = cy;
	hit_info->t = t;
	hit_info->normal = normal;
	hit_info->color = cylinder->color;
}

t_rgb	get_cylinder_head_color(t_cylinder *cylinder, t_hit_info *hit_info)
{
	if (cylinder->texture.type == TT_CHECKER)
		return (checker_cylinder_head(cylinder, hit_info));
	else if (cylinder->texture.type == TT_IMAGE)
		return (cylinder->color);
	else
		return (cylinder->color);
}
