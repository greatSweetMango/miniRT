/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_body2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:24:25 by gyim              #+#    #+#             */
/*   Updated: 2023/03/30 15:25:20 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	get_cylinder_body_color(t_cylinder *cylinder, t_hit_info *hit_info)
{
	if (cylinder->texture.type == TT_CHECKER)
		return (checker_cylinder_body(cylinder, hit_info));
	else if (cylinder->texture.type == TT_IMAGE)
		return (texture_cylinder_body(cylinder, hit_info));
	else
		return (cylinder->color);
}
