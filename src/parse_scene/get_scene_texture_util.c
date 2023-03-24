/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_texture_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:38:20 by gyim              #+#    #+#             */
/*   Updated: 2023/03/24 17:14:12 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_texture(t_texture *texture)
{
	texture->type = 0;
	texture->img = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->divid = 0;
}

int	set_texture_type(char *texture_type)
{
	if (texture_type == NULL)
		return (TT_NONE);
	else if (!ft_strncmp("ck", texture_type, 3))
		return (TT_CHECKER);
	else if (!ft_strncmp("img", texture_type, 4))
		return (TT_IMAGE);
	else
		puterr_exit("Parsing fail! (wrong texture type)");
	return (-1);
}
