/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:08:15 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/06 21:20:11 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	ft_ato_vec3(char *str)
{
	t_vec3	vec3;
	char	**values;

	values = ft_split(str, ",");
	if (!values[0] || !values[1] || !values[2] || values[3])
		puterr_exit("Parsing fail! (object's property is wrong)");
	vec3.x = ft_atod(values[0]);
	vec3.y = ft_atod(values[1]);
	vec3.z = ft_atod(values[2]);
	ft_split_free(values);
	return (vec3);
}
