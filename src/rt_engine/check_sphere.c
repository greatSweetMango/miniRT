/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/03/31 14:22:44 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_sphere_hit_info(t_hit_info *hit_info, t_list *sp, t_ray ray);

t_hit_info	check_all_sphere(t_ray ray, t_scene *scene)
{
	t_hit_info	target_object;
	t_hit_info	temp;
	t_list		*sphere;

	sphere = scene->spheres;
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
	double		t[2];
	t_sphere	*sphere;

	sphere = (t_sphere *)sp->content;
	hit_info.obj = NULL;
	v = v3_minus_v3(ray.pos, sphere->pos);
	discriminant = pow(v3_inner_product_v3(v, ray.orient), 2.0);
	discriminant -= ((v3_inner_product_v3(v, v)
				- pow(sphere->diameter / 2, 2.0)));
	if (discriminant < 0)
		return (hit_info);
	t[0] = -v3_inner_product_v3(v, ray.orient) + sqrt(discriminant);
	t[1] = -v3_inner_product_v3(v, ray.orient) - sqrt(discriminant);
	hit_info.t = find_t(t[0], t[1]);
	if (hit_info.t < 0)
		return (hit_info);
	set_sphere_hit_info(&hit_info, sp, ray);
	return (hit_info);
}

double	get_sphere_phi(t_vec3 point)
{
	double	ret;

	ret = atan2(point.y, point.x);
	if (ret < 0)
		ret += 2 * M_PI;
	return (ret);
}

double	get_sphere_theta(t_vec3	point)
{
	double	den;
	double	num;
	double	ret;

	num = point.z;
	den = sqrt(pow(point.x, 2.0) + pow(point.y, 2.0));
	ret = atan(den / num);
	if (ret < 0)
		ret = M_PI + ret;
	return (ret);
}

void	set_sphere_hit_info(t_hit_info *hit_info, t_list *sp, t_ray ray)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)sp->content;
	hit_info->obj = (t_list *)sp;
	hit_info->point = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, hit_info->t));
	hit_info->normal = v3_unit(v3_minus_v3(hit_info->point, sphere->pos));
	if (v3_inner_product_v3(v3_mul_d(hit_info->normal, -1.0), ray.orient) < 0.0)
		hit_info->obj = NULL;
	hit_info->ray = ray;
	hit_info->color = get_sphere_color(sphere, hit_info);
}
