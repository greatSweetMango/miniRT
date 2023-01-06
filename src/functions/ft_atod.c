/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:40:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:19:34 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_vars(double *dnum, int *sign, int *i, char *str)
{
	*dnum = 10;
	if (str[0] == '-')
	{
		*sign = -1;
		*i = 0;
	}
	else
	{
		*sign = 1;
		*i = -1;
	}
}

double	ft_atod(char *str)
{
	double	rv;
	double	dnum;
	int		sign;
	int		i;

	rv = 0;
	init_vars (&dnum, &sign, &i, str);
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
		{
			if (dnum == 10)
				rv = (rv * dnum) + ((str[i] - '0') * sign);
			else
			{
				rv += (str[i] - '0') * dnum * sign;
				dnum *= 0.1;
			}
		}
		else if (str[i] == '.' && dnum == 10)
			dnum = 0.1;
		else
			puterr_exit("Parsing fail! (object's property is wrong)");
	}
	return (rv);
}
