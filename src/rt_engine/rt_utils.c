/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:33 by gyim              #+#    #+#             */
/*   Updated: 2023/03/28 18:41:42 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	add_ambient_light(t_rgb color, t_ambient_lightning ambient_light)
{
	color.x = color.x * ambient_light.color.x * ambient_light.ratio;
	color.y = color.y * ambient_light.color.y * ambient_light.ratio;
	color.z = color.z * ambient_light.color.z * ambient_light.ratio;
	return (color);
}

double	find_t(double t1, double t2)
{
	if (t1 < 0 && t2 < 0)
		return (-1.0);
	if (t1 < t2)
	{
		if (t1 > 0)
			return (t1);
		else
			return (t2);
	}
	else
	{
		if (t2 > 0)
			return (t2);
		else
			return (t1);
	}
}

t_root	solve_equation(t_equation eq)
{
	t_root	root;
	double	discriminant;
	double	temp;

	discriminant = pow(eq.b, 2.0) - 4 * eq.a * eq.c;
	if (discriminant < 0)
	{
		root.valid = 0;
		return (root);
	}
	if (root.t1 < 0 && root.t2 < 0)
	{
		root.valid = 0;
		return (root);
	}
	root.valid = 1;
	root.t1 = -eq.b - sqrt(discriminant);
	root.t2 = -eq.b	+ sqrt(discriminant);
	if (root.t1 > root.t2)
	{
		temp = root.t1;
		root.t1 = root.t2;
		root.t2 = temp;
	}
	return (root);
}

double	find_root(double t[2], double coeff[3], double discriminant)
{
	double	temp;

	t[0] = (-coeff[1] - sqrt(discriminant)) / (2.0 * coeff[0]);
	t[1] = (-coeff[1] + sqrt(discriminant)) / (2.0 * coeff[0]);
	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
	return (find_t(t[0], t[1]));
}
