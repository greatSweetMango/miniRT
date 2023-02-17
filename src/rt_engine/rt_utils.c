/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:46:33 by gyim              #+#    #+#             */
/*   Updated: 2023/02/17 16:48:14 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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