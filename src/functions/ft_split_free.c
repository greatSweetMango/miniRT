/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:59:59 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:18:34 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_split_free(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
		free(str_arr[i++]);
	free(str_arr);
}
