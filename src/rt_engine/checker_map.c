/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:27:19 by gyim              #+#    #+#             */
/*   Updated: 2023/03/08 15:22:30 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_plane(t_plane *plane, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	double	alpha;
	double	beta;
	t_rgb	color;
	int		width;

	width = 10;
	center_to_point = v3_minus_v3(hit_info->point, plane->pos);
	alpha = v3_inner_product_v3(plane->dx, center_to_point);
	beta = v3_inner_product_v3(plane->dy, center_to_point);
	if (alpha < 0)
		alpha = alpha - width;
	if (beta < 0)
		beta = beta - width;
	if (((int)(alpha / width) + (int)(beta / width)) % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		v3_set(&color, 1.0, 1.0, 1.0);
	return (color);
}
