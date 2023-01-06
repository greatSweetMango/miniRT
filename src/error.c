/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:21:34 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:18:05 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	puterr_exit(char *str)
{
	ft_putstr_fd("Error\n", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(1);
}
