/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:59:09 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/07 10:07:27 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

/* BONUS HEADER */
#include <pthread.h>

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

/* FUNCTIONS *////////////////////////////////////////////

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
int		ft_rgb_to_i(t_rgb rgb);

//ft_split_free.c
void	ft_split_free(char **str_arr);

/* KEY_HOOKS *///////////////////////////////////////////////////////

// mouse_button.c
int	mouse_button(int btn, int x, int y, t_scene *scene);

// move_obj.c
void	move_obj(int keycode, t_vec3 *pos, t_screen screen);

// push_keys.c
int	push_keys(int keycode, t_scene *scene);

// push_keys.c
int	push_keys(int keycode, t_scene *scene);

// rotate_boj.c
void	get_rotation_matrix(float matrix[3][3], t_vec3 axis_norm, float theta);
t_vec3	rotate_by_dx_axis(t_vec3 orient, t_vec3 axis, double angle);
void	rotate_obj(int keycode, t_vec3 *orientation, t_scene *scene);
void	rotate_by_y_axis(t_vec3 *ori, double radian);

// update_camera.c
void	update_camera(int keycode, t_scene *scene);
void	switch_camera(int keycode, t_scene *scene);

// update_cone.c
void	update_cone(int keycode, t_scene *scene);

// update_cylinder.c
void	update_cylinder(int keycode, t_scene *scene);

// update_plane.c
void	update_plane(int keycode, t_scene *scene);

// update_sphere.c
void	update_sphere(int keycode, t_scene *scene);

/* nomalizetion */////////////////////////////////////////////////

//nomalize_camera_utils.c
void		set_planes_pos(t_list *planes, t_camera *now_cam);
void		set_cylinders_pos(t_list *cylinders, t_camera *now_cam);

//nomalize_camera.c
void		normalize_camera(t_scene *scene);
t_screen	get_screen(t_camera *camera);
void		set_cameras_pos(t_list *cameras, t_camera *now_cam);
void		set_lights_pos(t_list *lights, t_camera *now_cam);
void		set_spheres_pos(t_list *spheres, t_camera *now_cam);
void		set_cone_pos(t_list *cones, t_camera *now_cam);

/* OPERATORS *///////////////////////////////////////////////

// vec3_cross_product.c
t_vec3	v3_cross_product_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_cross_product_ds(t_vec3 v1, double x, double y, double z);

// vec3_div.c
t_vec3	v3_div_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_div_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_div_d(t_vec3 v1, double d);

// vec3_inner_product.c
double	v3_inner_product_v3(t_vec3 v1, t_vec3 v2);
double	v3_inner_product_ds(t_vec3 v1, double x, double y, double z);

// vec3_magnitude.c
float v3_magnitude(t_vec3 v);

// vec3_minus.c
t_vec3	v3_minus_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_minus_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_minus_d(t_vec3 v1, double d);

// vec3_multi.c
t_vec3	v3_mul_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_mul_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_mul_d(t_vec3 v1, double d);

// vec3_normalize.c
t_vec3 vec3_normalize(t_vec3 v);

// vec3_plus.c
t_vec3	v3_plus_v3(t_vec3 v1, t_vec3 v2);
t_vec3	v3_plus_ds(t_vec3 v1, double x, double y, double z);
t_vec3	v3_plus_d(t_vec3 v1, double d);

// vec3_set.c
void	v3_set(t_vec3 *v, double x, double y, double z);

//vec3_init.c
t_vec3	v3_unit(t_vec3 v);
double	l2norm(t_vec3 v);

/* PARSE SCENE *////////////////////////////////////////////

// parse_arg.c
void		objects_elements_check(t_scene *scene);
void		put2scene(t_scene *scene, char *line);
t_scene		*parse_arg(int argc, char **argv);

// set_scene_util.c
void	set_planes(t_scene *scene, char **object);
void	set_cylinders(t_scene *scene, char **object);
void	set_cones(t_scene *scene, char **object);

// set_scene.c
void	set_scene(t_scene *scene, char **object);
void	set_ambient_lightning(t_scene *scene, char **object);
void	set_cameras(t_scene *scene, char **object);
void	set_lights(t_scene *scene, char **object);
void	set_spheres(t_scene *scene, char **object);

/* RT ENGINE *////////////////////////////////////////////////
//check_cone_body.c
void	get_cone_body(t_hit_info *hit_info, t_ray, t_list *cone_list);
void	get_cone_coeff(t_ray ray, t_cone *cone,
		t_cone_var *variable);
void	get_cone_body_hit_point(t_hit_info *hit_info, t_list *cone_list,
				t_ray ray, t_cone_var variable);
double	check_corn_root(t_ray ray, t_cone *cone, t_cone_var variable);
//check_cone.c
t_hit_info	check_all_cone(t_ray ray, t_list *cone);
t_hit_info	check_cone(t_ray ray, t_list *cone);
t_cone_var	get_cone_var(t_ray ray, t_cone *cone);
//check_cylinder_body.c
void	get_cylinder_body(t_hit_info *hit_info, t_ray ray, t_list *cy);
void	get_cylinder_coeff(t_ray ray, t_cylinder *cylinder,
				t_cylinder_var *variable);
void	get_cylinder_alpha(t_cylinder_var *variable);
void	get_cylinder_body_hit_point(t_hit_info *hit_info, t_list *cy,
				t_ray ray, t_cylinder_var variable);
//check_cylinder_head.c
void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy);
double	check_cylinder_head(t_ray ray, t_vec3 pos, t_vec3 normal, double radius);

// check_cylinder.c
t_hit_info		check_all_cylinder(t_ray ray, t_list *cylinder);
t_hit_info		check_cylinder(t_ray ray, t_list *cy);
double			find_root(double t[2], double coeff[3], double discriminant);
t_cylinder_var	get_cylinder_var(t_ray ray, t_cylinder *cylinder);
// check_disk.c
void	get_cone_bottom(t_hit_info *hit_info, t_ray ray, t_list *cone_list);
double	check_disk(t_ray ray, t_vec3 pos, t_vec3 normal, double radius);
// check_light.c
t_hit_info	add_light(t_hit_info hit_info, t_list *lst_light, t_scene *scene);
double		get_light_ratio(t_hit_info hit_info, t_light *light, t_scene *scene);\
double		specular_light(t_hit_info hit_info, t_light *light);
double		get_distance(t_vec3 p1, t_vec3 p2);
// check_object.c
t_hit_info	check_objects(t_ray ray, t_scene *scene);
// check_plane.c
t_hit_info	check_all_plane(t_ray ray, t_list *plane);
t_hit_info	check_plane(t_ray ray, t_list *pl);
// check_sphere.c
t_hit_info	check_all_sphere(t_ray ray, t_list *sphare);
t_hit_info	check_sphere(t_ray ray, t_list *sp);
// get_hit_info.c

// ray.c
t_ray	get_ray_camera_to_obj(t_scene *scene, int w, int h);

// rt_engine.c
int		rt_engine(t_scene *scene, int w, int h);

// rt_utils.c
t_rgb	add_ambient_light(t_rgb color, t_ambient_lightning ambient_light);
double	find_t(double t1, double t2);

/* SOURCE CODES *////////////////////////////////////////////////

// camera.c
void	put_img(t_scene *scene, t_camera *camera, t_img *img);
void	set_screen(t_screen *screen, t_camera *camera);

// draw_scene.c
void	set_console_bg(t_scene *scene);
void	put_scene_to_img(t_scene *scene, t_img *img);
void	draw_scene(t_scene *scene);

// error.c
void	puterr_exit(char *str);

// main.c
int		close_scene(t_scene *scene);
void	init_img(t_scene *scene);
