/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:08:05 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 16:09:04 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	get_sphere_color(t_sphere *sphere, t_hit_info *hit_info)
{
	if (sphere->texture.type == TT_CHECKER)
		return (checker_sphere(sphere, hit_info));
	else if (sphere->texture.type == TT_IMAGE)
		return (texture_sphere(sphere, hit_info));
	else
		return (sphere->color);
}
