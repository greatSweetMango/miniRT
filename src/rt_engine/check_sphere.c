/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/03/12 19:52:43 by gyim             ###   ########seoul.kr  */
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
	v = v3_minus_v3(ray.pos, sphere->pos);
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
	hit_info.normal = v3_unit(v3_minus_v3(hit_info.point, sphere->pos));
	if (v3_inner_product_v3(v3_mul_d(hit_info.normal, -1.0), ray.orient) < 0.0)
		hit_info.obj = NULL;
	hit_info.ray = ray;
	// hit_info.color = sphere->color;
	hit_info.color = checker_sphere(sphere, &hit_info);
	// hit_info.color = texture_sphere(sphere, &hit_info);
	return (hit_info);
}

double	get_sphere_phi(t_vec3 point)
{
	double	ret;

	ret = atan(point.y / point.x);
	// if (ret < 0)
	// 	return (ret);
	return (ret);
}

double	get_sphere_theta(t_vec3	point)
{
	double	den;
	double	num;

	num = point.z;
	den = sqrt(pow(point.x, 2.0) + pow(point.y, 2.0));
	return (atan(den / num));
}