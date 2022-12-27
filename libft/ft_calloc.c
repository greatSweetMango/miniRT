/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:52:11 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rv;
	unsigned int	i;

	if (count != 0 && size != 0)
		if (count / size > UINT_MAX / size || size / count > UINT_MAX / size)
			exit(1);
	rv = (unsigned char *)malloc(count * size);
	if (!rv)
		exit(1);
	i = 0;
	while (i < count * size)
		rv[i++] = 0;
	return (rv);
}
