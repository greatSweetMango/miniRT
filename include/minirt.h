/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:59:09 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/30 19:51:45 by gyim             ###   ########seoul.kr  */
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

// ft_file_check.c
void	ft_file_check(const char *filename);

// ft_i_to_rgb.c
t_rgb   ft_i_to_rgb(int value);

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

// rotate_obj.c
t_vec3			quaternion_rotate(t_vec3 orient, t_vec3 axis, double angle);
t_quaternion	get_quaternion_conjugate(t_quaternion q);
t_quaternion	multiply_quaternion(t_quaternion a, t_quaternion b);
t_quaternion	get_quaternion_from_axis_angle(t_vec3 axis, double angle);
void			rotate_obj(int keycode, t_vec3 *orientation, t_scene *scene);
// void	get_rotation_matrix(float matrix[3][3], t_vec3 axis_norm, float theta);
// t_vec3	rotate_by_dx_axis(t_vec3 orient, t_vec3 axis, double angle);
// void	rotate_obj(int keycode, t_vec3 *orientation, t_scene *scene);
// void	rotate_by_y_axis(t_vec3 *ori, double radian);

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

// get_scene_texture_util.c
void    init_texture(t_texture *texture);
int		set_texture_type(char *texture_type);

// get_scene_texutre.c
void		set_plane_texture(t_scene *scene, t_texture *texture, char **object);
void		set_cylinder_texture(t_scene *scene, t_texture *texture, char **object);
void		set_sphere_texture(t_scene *scene, t_texture *texture, char **object);
t_texture	get_texture(t_scene *scene, char **object, int obj_type);

// parse_arg.c
void	objects_elements_check(t_scene *scene);
void	put2scene(t_scene *scene, char *line);
void	parse_arg(int argc, char **argv, t_scene *scene);

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
double		check_disk(t_ray ray, t_vec3 pos, t_vec3 normal, double radius);
//check_cylinder_body.c
void		get_cylinder_body(t_hit_info *hit_info, t_ray ray, t_list *cy);
t_equation	get_cylinder_var(t_ray ray, t_cylinder *cylinder);
int			get_cylinder_hit_point(t_hit_info *hit_info,
	t_cylinder *cylinder, t_ray ray, t_root root);
int			cylinder_height_check(t_cylinder *cylinder, t_vec3	point);
void		get_cylinder_body_normal(t_hit_info *hit_info, t_cylinder *cylinder);
//check_cylinder_body2.c
t_rgb		get_cylinder_body_color(t_cylinder *cylinder, t_hit_info *hit_info);
//check_cylinder_head.c
void	get_cylinder_head(t_hit_info *hit_info, t_ray ray, t_list *cy);
void	set_cylinder_head_hit_info(t_hit_info *hit_info, t_list *cy,
			double t, t_vec3 normal);
double	get_cylinder_head_t(t_cylinder *cylinder, t_ray ray, t_vec3 orient);
// t_rgb	get_cylinder_head_color(t_cylinder *cylinder, t_hit_info *hit_info);
// double	check_cylinder_head(t_ray ray, t_vec3 pos, t_vec3 normal, double radius);

// check_cylinder.c
t_hit_info		check_all_cylinder(t_ray ray, t_list *cylinder);
t_hit_info		check_cylinder(t_ray ray, t_list *cy);

// check_disk.c
void	get_cone_bottom(t_hit_info *hit_info, t_ray ray, t_list *cone_list);
// check_light.c
t_hit_info	add_light(t_hit_info hit_info, t_list *lst_light, t_scene *scene);
double		get_light_ratio(t_hit_info hit_info, t_light *light, t_scene *scene);\
double		specular_light(t_hit_info hit_info, t_light *light);
double		get_distance(t_vec3 p1, t_vec3 p2);
// check_object.c
t_hit_info	check_objects(t_ray ray, t_scene *scene);
// checker_cylinder.c
t_rgb	checker_cylinder_body(t_cylinder *cylinder, t_hit_info *hit_info);
t_rgb	get_cylinder_checker_color(double theta, double height,
	int width, t_hit_info *hit_info);
t_rgb	checker_cylinder_head(t_cylinder *cylinder, t_hit_info *hit_info);
// checker_plane.c
t_rgb	checker_plane(t_plane *plane, t_hit_info *hit_info);
// checker_sphere.c
t_rgb	checker_sphere(t_sphere *sphere, t_hit_info *hit_info);
void	get_sphere_phi_theta(double *phi, double *theta, t_vec3 point);
t_rgb	get_sphere_checker_color(double phi, double theta, t_sphere *sphere);
// check_plane.c
t_hit_info	check_all_plane(t_ray ray, t_list *plane);
t_hit_info	check_plane(t_ray ray, t_list *pl);
t_rgb		get_plane_color(t_plane *plane, t_hit_info *hit_info);
// check_sphere.c
t_hit_info	check_all_sphere(t_ray ray, t_scene *scene);
t_hit_info	check_sphere(t_ray ray, t_list *sp);
double		get_sphere_phi(t_vec3 point);
double		get_sphere_theta(t_vec3	point);
void		set_sphere_hit_info(t_hit_info *hit_info, t_list *sp, t_ray ray);
// check_sphere2.c
t_rgb		get_sphere_color(t_sphere *sphere, t_hit_info *hit_info);
// get_hit_info.c

// ray.c
t_ray	get_ray_camera_to_obj(t_scene *scene, int w, int h);

// rt_engine.c
int		rt_engine(t_scene *scene, int w, int h);

// rt_utils.c
t_rgb	add_ambient_light(t_rgb color, t_ambient_lightning ambient_light);
double	find_t(double t1, double t2);
t_root	solve_equation(t_equation eq);
double	find_root(double t[2], double coeff[3], double discriminant);
void	swap_double(double *a, double *b);

// texture_cylinder.c
t_rgb   texture_cylinder_body(t_cylinder *cylinder, t_hit_info *hit_info);
void	get_cylinder_theta_height(double *theta, double *height, t_cylinder *cylinder, t_hit_info *hit_info);
double	get_circle_theta(t_vec3 dr, t_vec3 x_axis, t_vec3 y_axis);

// texture_sphere.c
t_rgb	texture_sphere(t_sphere *sphere, t_hit_info *hit_info);
t_vec3	change_of_basis(t_vec3	center_to_point,
	t_vec3 x_axis, t_vec3 y_axis, t_vec3 z_axis);
void	get_sphere_texture_point(int *x, int *y,
	t_sphere *sphere, t_vec3 point);

// texture_plane.c
t_rgb   texture_plane(t_plane *plane, t_hit_info *hit_info);

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
