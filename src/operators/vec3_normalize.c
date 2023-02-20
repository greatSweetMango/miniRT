/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:05:48 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/20 20:14:03 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3 vec3_normalize(t_vec3 v)
{
	t_vec3	result;
    float	mag;
	
	mag = v3_magnitude(v);
	v3_set(&result, v.x / mag, v.y / mag, v.y / mag);
    return (result);
}