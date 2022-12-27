/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:54:13 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:54:14 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	if (c > 256)
		c %= 256;
	while (*s)
		s++;
	while (temp != s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	if (*temp == c || c == '\0')
		return (temp);
	else
		return (0);
}
