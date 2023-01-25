/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:42:50 by gyim              #+#    #+#             */
/*   Updated: 2023/01/25 19:43:08 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	raytracing(t_scene *scnen, t_screen *screen, t_img *img)
{
	t_vec3	dx;
	t_vec3	dy;
	t_vec3	curr;
	t_vec3	curr_y;
	int		i;
	int		j;
	t_rgb	black;
	t_rgb	white;

	black.r = 1;
	black.g = 1;
	black.b = 1;
	white.r = 0;
	white.g = 0;
	white.b = 0;
	dx = v3_div_d(screen->x_dir, WIN_WIDTH);
	dy = v3_div_d(screen->y_dir, WIN_HEIGHT);
	curr = screen->lowerleft;
	i = WIN_HEIGHT - 1;
	while (i >= 0)
	{
		j = 0;
		curr = curr_y;
		while (j < WIN_WIDTH)
		{
			if (check_object(curr, scnen))
				img->data[i * WIN_WIDTH + j] = ft_rgb_to_i(black);
			else
				img->data[i * WIN_WIDTH + j] = ft_rgb_to_i(white);
			curr = v3_plus_v3(curr, dx);
			j++;
		}
		curr_y = v3_plus_v3(curr_y, dy);
		i--;
	}	
}