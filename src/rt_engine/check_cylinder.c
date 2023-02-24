/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:37:58 by gyim              #+#    #+#             */
/*   Updated: 2023/02/24 17:07:40 by gyim             ###   ########seoul.kr  */
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
		temp = check_cylinder(ray, (t_cylinder *)cylinder->content);
		if (target_object.obj == NULL
			|| (temp.obj != NULL && temp.t < target_object.t))
			target_object = temp;
		cylinder = cylinder->next;
	}
	return (target_object);
}

t_hit_info	check_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_hit_info	hit_info;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		t1;
	double		t2;

	hit_info.obj = NULL;
	a = get_cylinder_a(ray, cylinder);
	b = get_cylinder_b(ray, cylinder);
	c = get_cylinder_c(ray, cylinder);
	discriminant = pow(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
		return (hit_info);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	hit_info.t = find_t(t1, t2);
	if (hit_info.t < 0)
		return (hit_info);
	hit_info.obj = (t_list *)cylinder;
	hit_info.point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info.t));
	hit_info.color = cylinder->color;
	return (hit_info);
}

double	get_cylinder_a(t_ray ray, t_cylinder *cylinder)
{
	t_vec3	p2;
	t_vec3	delta_p;
	double	dp;
	double	pp;
	double	result;

	p2 = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, cylinder->height));
	delta_p = v3_minus_v3(p2, cylinder->pos);
	dp = v3_inner_product_v3(cylinder->orientation, delta_p);
	pp = v3_inner_product_v3(delta_p, delta_p);
	result = v3_inner_product_v3(ray.orient, ray.orient);
	result -= 2 * pow(dp, 2.0) / pp;
	result += pow(dp, 2.0) / pp;
	return (result);
}

double	get_cylinder_b(t_ray ray, t_cylinder *cylinder)
{
	t_vec3	p2;
	t_vec3	delta_p;
	double	dp;
	double	pp;
	double	result;

	p2 = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, cylinder->height));
	delta_p = v3_minus_v3(p2, cylinder->pos);
	dp = v3_inner_product_v3(cylinder->orientation, delta_p);
	pp = v3_inner_product_v3(delta_p, delta_p);
	result = 2.0 * v3_inner_product_v3(
			v3_mul_d(cylinder->pos, -1.0), ray.orient);
	result -= 4.0 * v3_inner_product_v3(
			v3_mul_d(cylinder->pos, -1.0), delta_p) * dp / pp;
	result += 2.0 * v3_inner_product_v3(v3_mul_d(cylinder->pos, -1.0),
			delta_p) * dp / pp;
	return (result);
}

double	get_cylinder_c(t_ray ray, t_cylinder *cylinder)
{
	t_vec3	p0p1;
	t_vec3	p2;
	t_vec3	delta_p;
	double	pp;
	double	result;

	p0p1 = v3_minus_v3(ray.pos, v3_mul_d(cylinder->pos, -1.0));
	p2 = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, cylinder->height));
	delta_p = v3_minus_v3(p2, cylinder->pos);
	pp = v3_inner_product_v3(delta_p, delta_p);
	result = v3_inner_product_v3(p0p1, p0p1);
	result -= 2.0 * pow(v3_inner_product_v3(p0p1, delta_p), 2.0) / pp;
	result += pow(v3_inner_product_v3(p0p1, delta_p), 2.0) / pp;
	return (result);
}
