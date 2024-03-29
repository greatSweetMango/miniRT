/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:37:58 by gyim              #+#    #+#             */
/*   Updated: 2023/03/31 14:25:26 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_all_cylinder(t_ray ray, t_list *cylinder)
{
	t_hit_info	target_object;
	t_hit_info	temp;

	target_object.obj = NULL;
	while (cylinder != NULL)
	{
		temp = check_cylinder(ray, cylinder);
		if (target_object.obj == NULL
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		cylinder = cylinder->next;
	}
	return (target_object);
}

t_hit_info	check_cylinder(t_ray ray, t_list *cy)
{
	t_hit_info		hit_info;
	t_hit_info		hit_info2;

	get_cylinder_body(&hit_info, ray, cy);
	get_cylinder_head(&hit_info2, ray, cy);
	if (hit_info.obj && (hit_info2.obj == NULL || hit_info.t < hit_info2.t))
		return (hit_info);
	else
		return (hit_info2);
}
