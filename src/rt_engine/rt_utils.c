/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:33 by gyim              #+#    #+#             */
/*   Updated: 2023/03/02 19:12:37 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	add_ambient_light(t_rgb color, t_ambient_lightning ambient_light)
{
	color.x = color.x * ambient_light.color.x * ambient_light.ratio;
	color.y = color.y * ambient_light.color.y * ambient_light.ratio;
	color.z = color.z * ambient_light.color.z * ambient_light.ratio;
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
