/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:21:03 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 18:22:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_plane(t_plane *plane, t_hit_info *hit_info)
{
	t_vec3	center_to_point;
	double	alpha;
	double	beta;
	t_rgb	color;

	plane->dx = v3_unit(
			v3_cross_product_ds(plane->orientation, 0.0, -1.0, 0.0));
	plane->dy = v3_cross_product_v3(plane->orientation, plane->dx);
	center_to_point = v3_minus_v3(hit_info->point, plane->pos);
	alpha = v3_inner_product_v3(plane->dx, center_to_point);
	beta = v3_inner_product_v3(plane->dy, center_to_point);
	if (alpha < 0)
		alpha = alpha - plane->texture.width;
	if (beta < 0)
		beta = beta - plane->texture.height;
	if (((int)(alpha / plane->texture.width)
		+ (int)(beta / plane->texture.height)) % 2 == 0)
		v3_set(&color, 0, 0, 0);
	else
		v3_set(&color, 1.0, 1.0, 1.0);
	return (color);
}
