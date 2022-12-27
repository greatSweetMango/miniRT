/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:53:42 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:53:43 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len_s;

	if (!s)
		return ;
	len_s = ft_strlen((char *)s);
	i = 0;
	while (i < (unsigned int)len_s)
	{
		f(i, &s[i]);
		i++;
	}
}
