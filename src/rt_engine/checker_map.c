/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:27:19 by gyim              #+#    #+#             */
/*   Updated: 2023/03/07 16:06:30 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	checker_plane(t_plane *plane, t_hit_info *hit_info)
{
	t_vec3	center_to_point;

	center_to_point = v3_minus_v3(hit_info->point, plane->pos);
	
}
