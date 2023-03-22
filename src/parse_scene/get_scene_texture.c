/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:39 by gyim              #+#    #+#             */
/*   Updated: 2023/03/22 19:22:16 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_plane_texture(t_scene *scene, t_texture *texture, char **object)
{
	texture->type = set_texture_type(object[0]);
	if (texture->type == TT_NONE)
		return ;
	if (texture->type == TT_IMAGE && object[1] && object[2]
		&& object[3] && !object[4])
	{
		texture->width = ft_atoi(object[1]);
		texture->height = ft_atoi(object[2]);
		ft_file_check(object[3]);
		texture->img = mlx_xpm_file_to_image(scene->mlx, object[3], &texture->width, &texture->height);
	}
	else if (texture->type == TT_CHECKER && object[1] && object[2] && !object[3])
	{
		texture->width = ft_atoi(object[1]);
		texture->height = ft_atoi(object[2]);
	}
	else
		puterr_exit("Parsing fail! (get_plane_texture())");
}

void	set_cylinder_texture(t_scene *scene, t_texture *texture, char **object)
{
	texture->type = set_texture_type(object[0]);
	if (texture->type == TT_NONE)
		return ;
	if (texture->type == TT_IMAGE && object[1] && !object[2])
	{
		ft_file_check(object[1]);
		texture->img = mlx_xpm_file_to_image(scene->mlx, object[1], &texture->width, &texture->height);
	}
	else if (texture->type == TT_CHECKER && object[1] && !object[2])
		texture->divid = ft_atoi(object[1]);
	else
		puterr_exit("Parsing fail! (get_cylinder_texture())");
}

void	set_sphere_texture(t_scene *scene, t_texture *texture, char **object)
{
	texture->type = set_texture_type(object[0]);
	if (texture->type == TT_NONE)
		return ;
	if (texture->type == TT_IMAGE && object[1] && !object[2])
	{
		ft_file_check(object[1]);
		texture->img = mlx_xpm_file_to_image(scene->mlx, object[1], &texture->width, &texture->height);
	}
	else if (texture->type == TT_CHECKER && object[1] && !object[2])
		texture->divid = ft_atoi(object[1]);
	else
		puterr_exit("Parsing fail! (get_sphere_texture()");
}
 
t_texture get_texture(t_scene *scene, char **object, int obj_type)
{
	t_texture	texture;

	init_texture(&texture);
	if (obj_type == SPHERE)
		set_sphere_texture(scene, &texture, object);
	else if (obj_type == CYLINDER)
		set_cylinder_texture(scene, &texture, object);
	else if (obj_type == PLANE)
		set_plane_texture(scene, &texture, object);
	else
		puterr_exit("Parsing fail! (error int get_texture( char **, int ))");
	return (texture);
}