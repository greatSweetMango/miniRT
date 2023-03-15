/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:39 by gyim              #+#    #+#             */
/*   Updated: 2023/03/15 19:16:20 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    init_texture(t_texture *texture)
{
	texture->type = 0;
	texture->img = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->divid = 0;
}
int get_texture_type(char *texture_type)
{
	if (texture_type == NULL)
		return (TT_NONE);
	else if (!ft_strncmp("ck", texture_type, 3))
		return (TT_CHECKER);
	else if (!ft_strncmp("img", texture_type, 4))
		return (TT_IMAGE);
	else
		puterr_exit("Parsing fail! (wrong texture type)");
}

t_texture	get_sphere_texture(char **object)
{
	t_texture   texture;

	init_texture(&texture);
	texture.type = get_texture_type(object[0]);
	if (texture.type == TT_IMAGE)
	{
	}
	else if (texture.type == TT_CHECKER && object[1])
		puterr_exit("Parsing fail! (get_phsere_texture(object))");

	return (texture);
}

t_texture	get_texture(char **object, int obj_type)
{
	t_texture	texture;

	if (obj_type == SPHERE)
		texture = get_sphere_texture(object);
	else if (obj_type == PLANE)
		texture = get_plane_texture(object);
	else if (obj_type == CYLINDER)
		texture = get_cylinder_texture(object);
	else
		puterr_exit("Parsing fail! (error int get_texture( char **, int ))");
	return (texture);
}