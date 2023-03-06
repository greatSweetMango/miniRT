/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:31:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/06 18:34:46 by jaehyuki         ###   ########.fr       */
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
	rgb.x = ft_atoi(values[0]) / 255.0;
	if (rgb.x < 0 || rgb.x > RGB_MAX)
		puterr_exit("Parsing fail! RGB(r) vaule is wrong");
	rgb.y = ft_atoi(values[1]) / 255.0;
	if (rgb.y < 0 || rgb.y > RGB_MAX)
		puterr_exit("Parsing fail! RGB(g) vaule is wrong");
	rgb.z = ft_atoi(values[2]) / 255.0;
	if (rgb.z < 0 || rgb.z > RGB_MAX)
		puterr_exit("Parsing fail! RGB(b) vaule is wrong");
	ft_split_free(values);
	return (rgb);
}
