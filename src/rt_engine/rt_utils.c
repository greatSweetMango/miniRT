/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:33 by gyim              #+#    #+#             */
/*   Updated: 2023/03/01 13:20:44 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	add_ambient_light(t_rgb color, t_ambient_lightning ambient_light)
{
	color.r = color.r * ambient_light.color.r * ambient_light.ratio;
	color.g = color.g * ambient_light.color.g * ambient_light.ratio;
	color.b = color.b * ambient_light.color.b * ambient_light.ratio;
	return (color);
}

double	find_t(double t1, double t2)
{
	if (t1 < 0 && t2 < 0)
		return (-1.0);
	if (t1 < t2)
	{
		if (t1 > 0)
			return (t1);
		else
			return (t2);
	}
	else
	{
		if (t2 > 0)
			return (t2);
		else
			return (t1);
	}
}
