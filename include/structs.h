/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:52:47 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/28 18:33:21 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* BASE */

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_texture
{
	int		type; //NONE 0, CHECKER 1, IMG 2 [  , ck, img]
	t_img	*img; // IMG;
	int		width; // PLANE (IMG O)
	int		height;	// PALNE (IMG O)
	int		divid; // CYLINDER, SPHERE (IMG X)
}	t_texture;

typedef struct s_quaternion{
    double  w;
    double  x;
    double  y;
    double  z;

} t_quaternion;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec3	t_rgb;

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
	int		is_set;
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
	t_vec3		pos;
	double		diameter;
	t_rgb		color;
	t_vec3		orientation;
	t_vec3		x_axis;
	t_texture	texture;
}	t_sphere;

typedef struct s_plane
{
	t_vec3		pos;
	t_vec3		orientation;
	t_rgb		color;
	t_texture	texture;
	t_vec3		dx;
	t_vec3		dy;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3		pos;
	t_vec3		orientation;
	t_vec3		x_axis;
	double		diameter;
	double		height;
	t_rgb		color;
	t_texture	texture;
}	t_cylinder;

typedef struct s_cone
{
	t_vec3	pos;
	t_vec3	orientation;
	double	diameter;
	double	height;
	t_rgb	color;
}	t_cone;

typedef struct s_screen
{
	t_vec3	orient;
	t_vec3	x_dir;
	t_vec3	y_dir;
	double	theta;
	t_vec3	p1m;
}	t_screen;

typedef struct s_ray
{
	t_vec3	pos;
	t_vec3	orient;
}	t_ray;

typedef struct s_hit_info
{
	t_list	*obj;
	double	t;
	t_vec3	point;
	t_rgb	color;
	t_ray	ray;
	t_vec3	normal;
}	t_hit_info;

/* object variable */

typedef struct s_root
{
	double	t1;
	double	t2;
	int		valid;
}	t_root;

typedef struct s_equation
{
	double	a;
	double	b;
	double	c;
}	t_equation;

typedef struct s_cone_var
{
	t_vec3	cone_orient;
	t_vec3	p2p0;
	double	theta;
	t_vec3	ray_orient;
	double	cos_thata;
	t_vec3	peak;
	t_vec3	edge;
	double	t[2];
	double	coeff[3];
	double	alpha[2];
}	t_cone_var;

/* Main Structs */

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
	t_list				*cones;
	t_list				*selected_obj;
}	t_scene;

// Bonuse structs
typedef struct s_thread
{
	t_scene		*scene;
	t_img		*img;
	int			thread_no;
	pthread_t	th;
}	t_thread;

#endif