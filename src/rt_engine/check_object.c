/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:48 by gyim              #+#    #+#             */
/*   Updated: 2023/02/17 16:50:03 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_sphere(t_vec3	ray, t_sphere *sphere)
{
	double	discriminant;
	t_vec3	v;
	double	t1;
	double	t2;
	double	our_t;

	v = v3_mul_d(sphere->pos, -1.0);
	discriminant = pow(v3_inner_product_v3(v, ray), 2.0);
	discriminant -= ((v3_inner_product_v3(v, v)
				- pow(sphere->diameter / 2, 2.0)));
	if (discriminant < 0)
		return (0);	
	t1 = -v3_inner_product_v3(v, ray) + sqrt(discriminant);
	t2 = -v3_inner_product_v3(v, ray) - sqrt(discriminant);
	our_t = find_t(t1, t2);
	if (our_t < 0)
		return (0);
	else
		return (1);
	return (1);
}
