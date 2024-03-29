/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:02:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/30 17:42:23 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	texture_plane(t_plane *plane, t_hit_info *hit_info)
{
	t_vec3			center_to_point;
	double			alpha;
	double			beta;
	int				x;
	int				y;

	plane->dx = v3_unit(
			v3_cross_product_ds(plane->orientation, 0.0, -1.0, 0.0));
	plane->dy = v3_cross_product_v3(plane->orientation, plane->dx);
	center_to_point = v3_minus_v3(hit_info->point, plane->pos);
	alpha = v3_inner_product_v3(plane->dx, center_to_point);
	beta = v3_inner_product_v3(plane->dy, center_to_point);
	if (alpha < 0)
		alpha = -alpha;
	if (beta < 0)
		beta = -beta;
	x = (int)alpha % plane->texture.width;
	y = (int)beta % plane->texture.height;
	return (ft_i_to_rgb(
			plane->texture.img->data[y * plane->texture.width + x]));
}
