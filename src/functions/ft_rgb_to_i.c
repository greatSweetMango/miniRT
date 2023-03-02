/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:12:24 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/02 19:21:58 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_rgb_to_i(t_rgb rgb)
{
	int	num;

	if (rgb.x > 1)
		rgb.x = 1.0;
	if (rgb.y > 1)
		rgb.y = 1.0;
	if (rgb.z > 1)
		rgb.z = 1.0;
	num = 0;
	num += (int)(rgb.x *255) * 0x010000;
	num += (int)(rgb.y *255) * 0x000100;
	num += (int)(rgb.z *255) * 0x000001;
	return (num);
}
