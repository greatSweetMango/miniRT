/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:43:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/01 18:44:41 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

	//get_screen(scene);
	//get_레이저 쏠 좌표(screen, w, h)
	//raytracing()
	//계산(scnen, 레이저 쏠 좌표)
int	rt_engine(t_scene *scene, int w, int h)
{
	normalize_camera(scene);
	return (ft_rgb_to_i(raytracing(scene, w, h)));
}
