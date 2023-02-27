/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/02/27 20:05:31 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit_info	check_all_sphere(t_ray ray, t_list *sphere)
{
	t_hit_info	target_object;
	t_hit_info	temp;

	target_object.obj = NULL;
	while (sphere != NULL)
	{
		temp = check_sphere(ray, sphere);
		if (target_object.obj == NULL 
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		sphere = sphere->next;
	}
	return (target_object);
}

t_hit_info	check_sphere(t_ray ray, t_list *sp)
{
	t_hit_info	hit_info;
	double		discriminant;
	t_vec3		v;
	double		t1;
	double		t2;
	t_sphere	*sphere;

	sphere = (t_sphere *)sp->content;
	hit_info.obj = NULL;
	v = v3_mul_d(sphere->pos, -1.0);
	discriminant = pow(v3_inner_product_v3(v, ray.orient), 2.0);
	discriminant -= ((v3_inner_product_v3(v, v)
				- pow(sphere->diameter / 2, 2.0)));
	if (discriminant < 0)
		return (hit_info);
	t1 = -v3_inner_product_v3(v, ray.orient) + sqrt(discriminant);
	t2 = -v3_inner_product_v3(v, ray.orient) - sqrt(discriminant);
	hit_info.t = find_t(t1, t2);
	if (hit_info.t < 0)
		return (hit_info);
	hit_info.obj = (t_list *)sp;
	hit_info.point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info.t));
	// multiply ambient
	hit_info.color.r = sphere->color.r * 0.15;
	hit_info.color.g = sphere->color.g * 0.15;
	hit_info.color.b = sphere->color.b * 0.15;
	return (hit_info);
}
