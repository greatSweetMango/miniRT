/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:31:15 by gyim              #+#    #+#             */
/*   Updated: 2023/01/25 18:15:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_img(t_scene *scnen, t_camera *camera, t_img *img)
{
	t_screen	screen;

	set_screen(&screen, camera);
	raycasting(screen, scnen);
}

void	set_screen(t_screen *screen, t_camera *camera)
{
	screen.orient = v3_unit(camera->orientation);
	screen.x_dir = v3_cross_product_ds(orient, 0, 1, 0);
	screen.y_dir = v3_cross_product_v(x_dir, orient);
	screen.lowerleft = v3_minus_v(orient, v3_plus_v3(x_dir, y_dir));
	screen.upperright = v3_plus_v3(orient, v3_plut_v3(x_dir, y_dir));
}
