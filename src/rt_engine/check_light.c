/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:08:00 by gyim              #+#    #+#             */
/*   Updated: 2023/02/28 19:34:49 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	add_light(t_hit_info hit_info, t_list *light)
{
	t_list	*curr_light;
	double	light_ratio;

	curr_light = light;
	if (hit_info.obj == NULL || hit_info.obj->obj_type == SPHERE)
	{
		while (curr_light)
		{
			light_ratio = get_light_ratio(hit_info,
					(t_light *)curr_light->content);
			hit_info.color.r += light_ratio
				* ((t_light *)(curr_light->content))->ratio
				* ((t_light *)(curr_light->content))->color.r;
			hit_info.color.g += light_ratio
				* ((t_light *)(curr_light->content))->ratio
				* ((t_light *)(curr_light->content))->color.g;
			hit_info.color.b += light_ratio
				* ((t_light *)(curr_light->content))->ratio
				* ((t_light *)(curr_light->content))->color.b;
			curr_light = curr_light->next;
		}
	}
	return (hit_info);
}

double	get_light_ratio(t_hit_info hit_info, t_light *light)
{
	double	ratio;

	ratio = v3_inner_product_v3(hit_info.normal,
			v3_unit(v3_minus_v3(hit_info.point, light->pos)));
	printf("normal : %f %f %f\n", hit_info.normal.x, hit_info.normal.y, hit_info.normal.z);
	printf("ltop   : %f %f %f\n",
		v3_unit(v3_minus_v3(hit_info.point, light->pos)).x,
		v3_unit(v3_minus_v3(hit_info.point, light->pos)).y,
		v3_unit(v3_minus_v3(hit_info.point, light->pos)).z);
	if (ratio < 0)
		return (0.0);
	return (ratio);
}
