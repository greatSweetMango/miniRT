/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:44:45 by gyim              #+#    #+#             */
/*   Updated: 2023/01/25 17:01:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v3_unit(t_vec3 v)
{
	t_vec3	unit_vector;
	double	norm;

	norm = l2norm(v);
	unit_vector = v3_div_d(v, norm);
	return (unit_vector);
}

double	l2norm(t_vec3	v)
{
	return (sqrt(v3_inner_product_v(v, v)));
}
