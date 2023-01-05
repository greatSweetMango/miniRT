/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:52:47 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/04 20:22:24 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* BASE */
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef	struct s_list
{
	void			*content;
	struct s_list	*pre;
	struct s_list	*next;
}	t_list;

/* OBJECTS */

typedef struct s_ambient_lightning
{
	double	ratio;
	t_rgb	color;
}	t_ambient_lightning;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orientation;
	t_vec3	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_rgb	color;
}	t_light;

typedef struct s_sphere
{
	t_vec3	pos;
	double	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	orientation;
	t_rgb	color;
}	t_plane;

typedef struct t_cylinder
{
	t_vec3	pos;
	t_vec3	orientation;
	double	diameter;
	double	height;
	t_rgb	color;
}	t_sylinder;

typedef struct s_scene
{
	t_ambient_lightning	ambient_lightning;
	t_list				*cameras;
	t_list				*lights;
	t_list				*spheres;
	t_list				*planes;
	t_list				*squares;
	t_list				*cylinders;
	t_list				*triangles;
}	t_scene;
