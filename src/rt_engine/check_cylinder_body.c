/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder_body.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:29:34 by gyim              #+#    #+#             */
/*   Updated: 2023/03/28 19:43:17 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_body(t_hit_info *hit_info, t_ray ray, t_list *cy)
{
	t_cylinder		*cylinder;
	t_equation		var;
	t_root			root;

	hit_info->obj = NULL;
	cylinder = (t_cylinder *)cy->content;
	var = get_cylinder_var(ray, cylinder);
	root = solve_equation(var);
	if (!root.valid)
		return ;
	if (!get_cylinder_hit_point(hit_info, cylinder, ray, root))
		return ;
	hit_info->obj = cy;
	get_cylinder_body_normal(hit_info, cylinder);
	hit_info->ray = ray;
	hit_info->color = cylinder->color;
}

t_equation	get_cylinder_var(t_ray ray, t_cylinder *cylinder)
{
	t_equation		var;
	t_vec3			w;
	t_vec3			c;

	c = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, -0.5 * cylinder->height));
	w = v3_minus_v3(ray.pos, c);
	var.a = v3_inner_product_v3(ray.orient, ray.orient);
	var.a -= pow(v3_inner_product_v3(ray.orient, cylinder->orientation), 2.0);
	var.b = v3_inner_product_v3(ray.orient, w);
	var.b -= v3_inner_product_v3(ray.orient, cylinder->orientation)
		* v3_inner_product_v3(w, cylinder->orientation);
	var.b *= 2.0;
	var.c = v3_inner_product_v3(w, w);
	var.c -= pow(v3_inner_product_v3(w, cylinder->orientation), 2.0);
	var.c -= pow(cylinder->diameter / 2.0, 2.0);
	return (var);
}

int	get_cylinder_hit_point(t_hit_info *hit_info,
	t_cylinder *cylinder, t_ray ray, t_root root)
{
	t_vec3	l1;
	t_vec3	l2;

	if (root.t1 >= 0)
	{
		l1 = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, root.t1));
		if (cylinder_height_check(cylinder, l1))
		{
			hit_info->point = l1;
			hit_info->t = root.t1;
			return (1);
		}
	}
	if (root.t2 >= 0)
	{
		l2 = v3_plus_v3(ray.pos, v3_mul_d(ray.orient, root.t2));
		if (cylinder_height_check(cylinder, l2))
		{
			hit_info->point = l2;
			hit_info->t = root.t2;
			return (1);
		}
	}
	return (0);
}

int	cylinder_height_check(t_cylinder *cylinder, t_vec3	point)
{
	t_vec3	lcenter;
	t_vec3	lcenter_to_point;
	double	height;

	lcenter = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, -0.5 * cylinder->height));
	lcenter_to_point = v3_minus_v3(point, lcenter);
	height = v3_inner_product_v3(lcenter_to_point, cylinder->orientation);
	printf("height : %f %f\n", height, cylinder->height);
	if (height < 0 || height > cylinder->height)
		return (0);
	return (1);
}

void	get_cylinder_body_normal(t_hit_info *hit_info, t_cylinder *cylinder)
{
	t_vec3	lcenter;
	t_vec3	lcenter_to_point;
	t_vec3	height;

	lcenter = v3_plus_v3(cylinder->pos,
			v3_mul_d(cylinder->orientation, -0.5 * cylinder->height));
	lcenter_to_point = v3_minus_v3(hit_info->point, lcenter);
	height = v3_mul_d(cylinder->orientation,
			v3_inner_product_v3(lcenter_to_point, cylinder->orientation));
	hit_info->normal = v3_unit(v3_minus_v3(lcenter_to_point, height));
}

t_rgb	get_cylinder_body_color(t_cylinder *cylinder, t_hit_info *hit_info)
{
	if (cylinder->texture.type == TT_CHECKER)
		return (checker_cylinder_body(cylinder, hit_info));
	else if (cylinder->texture.type == TT_IMAGE)
		return (texture_cylinder_body(cylinder, hit_info));
	else
		return (cylinder->color);
}
