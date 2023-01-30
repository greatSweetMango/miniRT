/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomalize_camera_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:31:15 by gyim              #+#    #+#             */
/*   Updated: 2023/01/30 19:12:23 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_cylinders_pos(t_list *cylinders, t_camera *now_cam)
{
	t_cylinder	*cylinder;

	while (cylinders)
	{
		cylinder = cylinders->content;
		cylinder->pos = v3_minus_v3(cylinder->pos, now_cam->pos);
		cylinders = cylinders->next;
	}
}

void	set_planes_pos(t_list *planes, t_camera *now_cam)
{
	t_plane	*plane;

	while (planes)
	{
		plane = planes->content;
		plane->pos = v3_minus_v3(plane->pos, now_cam->pos);
		planes = planes->next;
	}
}
