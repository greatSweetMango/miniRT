/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:31:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:40:38 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	ft_ato_rgb(char *str)
{
	t_rgb	rgb;
	char	**values;

	values = ft_split(str, ",");
	if (!values[0] || !values[1] || !values[2] || values[3])
		puterr_exit("Parsing fail! (object's property is wrong)");
	rgb.r = ft_atoi(values[0]);
	if (rgb.r < 0 || rgb.r > RGB_MAX)
		puterr_exit("Parsing fail! RGB(r) vaule is wrong");
	rgb.g = ft_atoi(values[1]);
	if (rgb.g < 0 || rgb.g > RGB_MAX)
		puterr_exit("Parsing fail! RGB(g) vaule is wrong");
	rgb.b = ft_atoi(values[2]);
	if (rgb.b < 0|| rgb.b > RGB_MAX)
		puterr_exit("Parsing fail! RGB(b) vaule is wrong");
	ft_split_free(values);
	return (rgb);
}
