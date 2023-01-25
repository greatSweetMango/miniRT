/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:59:09 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/25 19:41:16 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

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
t_list	*ft_lstnew(void	*content, int obj_type);

// ft_rgb_to_i.c
int	ft_rgb_to_i(t_rgb rgb);

//ft_split_free.c
void	ft_split_free(char **str_arr);

/* KEY_HOOKS */

// mouse_button.c
int	mouse_button(int btn, int x, int y, void *param);

/* OPERATORS */

// vec3_cross_product.c
t_vec3	v3_cross_product_v(t_vec3 v1, t_vec3 v2);
t_vec3	v3_cross_product_ds(t_vec3 v1, double x, double y, double z);
// vec3_div.c
t_vec3	v3_div_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_div_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_div_d(t_vec3 v1, double d);
// vec3_inner_product.c
double	v3_inner_product_v(t_vec3 v1, t_vec3 v2);
double	v3_inner_product_ds(t_vec3 v1, double x, double y, double z);

// vec3_minus.c
t_vec3	v3_minus_v(t_vec3 v1, t_vec3 v2);
t_vec3	v3_minus_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_minus_d(t_vec3 v1, double d);

// vec3_multi.c
t_vec3	v3_mul_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_mul_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_mul_d(t_vec3 v1, double d);

//vec3_plus.c
t_vec3	v3_plus_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_plus_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_plus_d(t_vec3 v1, double d);

//vec3_init.c
t_vec3	v3_unit(t_vec3 v);
double	l2norm(t_vec3 v);

/* SOURCE CODES */

// camera.c
void	put_img(t_scene *scene, t_camera *camera, t_img *img);
void	set_screen(t_screen *screen, t_camera *camera);

// draw_scene.c
void	put_scene_to_img(t_scene *scene, t_img *img);
void	draw_scene(t_scene *scene);
void	raytracing(t_scene *scnen, t_screen *screen, t_img *img);

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
