/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:00 by gyim              #+#    #+#             */
/*   Updated: 2023/03/01 17:40:04 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	add_light(t_hit_info hit_info, t_list *light)
{
	t_list	*curr_light;
	double	density;

	curr_light = light;
	if (hit_info.obj != NULL && hit_info.obj->obj_type == SPHERE)
	{
		while (curr_light)
		{
			density = get_light_ratio(hit_info,
					(t_light *)curr_light->content);
			hit_info.color.r += density
				* ((t_light *)(curr_light->content))->ratio
				* ((t_light *)(curr_light->content))->color.r;
			hit_info.color.g += density
				* ((t_light *)(curr_light->content))->ratio
				* ((t_light *)(curr_light->content))->color.g;
			hit_info.color.b += density
				* ((t_light *)(curr_light->content))->ratio
				* ((t_light *)(curr_light->content))->color.b;
			if (hit_info.color.r > 1)
				hit_info.color.r = 1.0;
			if (hit_info.color.g > 1)
				hit_info.color.g = 1.0;
			if (hit_info.color.b > 1)
				hit_info.color.b = 1.0;
			curr_light = curr_light->next;
		}
	}
	return (hit_info);
}

double	get_light_ratio(t_hit_info hit_info, t_light *light)
{
	double	ratio;

	ratio = v3_inner_product_v3(hit_info.normal,
			v3_unit(v3_minus_v3(light->pos, hit_info.point)));
	if (ratio < 0)
		return (0.0);
	return (ratio);
}
