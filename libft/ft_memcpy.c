/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:54 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:52:54 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*rv;
	unsigned char	*temp;

	if (!dst && !src && n > 0)
		return (dst);
	rv = (unsigned char *)dst;
	temp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		rv[i] = (unsigned char)temp[i];
		i++;
	}
	return (rv);
}
