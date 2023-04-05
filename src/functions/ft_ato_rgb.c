/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:31:16 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/04/05 09:07:46 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	ft_ato_rgb(char *str)
{
	t_rgb	rgb;
	char	**values;
	int		rgb_value;

	values = ft_split(str, ",");
	if (!values[0] || !values[1] || !values[2] || values[3])
		puterr_exit("Parsing fail! (object's property is wrong)");
	rgb_value = ft_atoi(values[0]);
	if (rgb_value < 0 || rgb_value > RGB_MAX)
		puterr_exit("Parsing fail! RGB(r) vaule is wrong");
	rgb.x = (double)rgb_value / 255.0;
	rgb_value = ft_atoi(values[0]);
	if (rgb_value < 0 || rgb_value > RGB_MAX)
		puterr_exit("Parsing fail! RGB(g) vaule is wrong");
	rgb.y = (double)rgb_value / 255.0;
	rgb_value = ft_atoi(values[2]);
	if (rgb_value < 0 || rgb_value > RGB_MAX)
		puterr_exit("Parsing fail! RGB(b) vaule is wrong");
	rgb.z = (double)rgb_value / 255.0;
	ft_split_free(values);
	return (rgb);
}
