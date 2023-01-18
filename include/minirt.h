/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:59:09 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/18 19:48:16 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* STANDARD HEADER */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>

/* Library */
#include "libft.h"
#include "mlx.h"

#include "defines.h"
#include "structs.h"

/* FUNCTIONS */

// ft_ato_rgb.c
t_rgb	ft_ato_rgb(char *str);

// ft_ato_vec3.c
t_vec3	ft_ato_vec3(char *str);

// ft_atod.c
double	ft_atod(char *str);

// ft_lst.c
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void	*content);

// ft_rgb_to_i.c
int	ft_rgb_to_i(t_rgb rgb);

//ft_split_free.c
void	ft_split_free(char **str_arr);

/* SOURCE CODES */

// draw_scene.c
void	put_scene_to_img(t_scene *scene, t_img *img);
void	draw_scene(t_scene *scene);

// error.c
void	puterr_exit(char *str);

// main.c
int		close_scene(t_scene *scene);
void	init_img(t_scene *scene);

// parse_arg.c
void		put2scene(t_scene *scene, char *line);
t_scene		*parse_arg(int argc, char **argv);

// push_keys.c
int	push_keys(int keycode, t_scene *scene);

// set_scene.c
void	set_scene(t_scene *scene, char **object);
void	set_ambient_lightning(t_scene *scene, char **object);
void	set_cameras(t_scene *scene, char **object);
void	set_lights(t_scene *scene, char **object);
void	set_spheres(t_scene *scene, char **object);

// set_scene_util.c
void	set_planes(t_scene *scene, char **object);
void	set_cylinders(t_scene *scene, char **object);
