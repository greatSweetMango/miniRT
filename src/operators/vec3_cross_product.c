/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:51:26 by gyim              #+#    #+#             */
/*   Updated: 2023/02/23 19:52:30 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	v3_cross_product_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = -v1.x * v2.z + v1.z * v2.x;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

t_vec3	v3_cross_product_ds(t_vec3 v1, double x, double y, double z)
{
	t_vec3	ret;

	ret.x = v1.y * z - v1.z * y;
	ret.y = -v1.x * z + v1.z * x;
	ret.z = v1.x * y - v1.y * x;
	return (ret);
}
