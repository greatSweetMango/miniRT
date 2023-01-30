/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:52:47 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/30 20:10:11 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef STRUCTS_H
# define STRUCTS_H

/* BASE */
typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_list
{
	int				obj_type;
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
	double	fov;
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

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	orientation;
	double	diameter;
	double	height;
	t_rgb	color;
}	t_cylinder;

typedef struct s_screen
{
	t_vec3	orient;
	t_vec3	lowerleft;
	t_vec3	upperright;
	t_vec3	x_dir;
	t_vec3	y_dir;
}	t_screen;

/* Main Structs */

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_scene
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_ambient_lightning	ambient_lightning;
	t_screen			screen;
	t_list				*cameras;
	t_list				*lights;
	t_list				*spheres;
	t_list				*planes;
	t_list				*cylinders;
	t_list				*selected_obj;
}	t_scene;

#endif