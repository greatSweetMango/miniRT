/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:52:47 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/02 20:40:33 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

typedef struct s_scene
{
	t_list			*cameras;
	t_list			*lights;
	t_list			*spheres;
	t_list			*planes;
	t_list			*squares;
	t_list			*cylinders;
	t_list			*triangles;
}	t_scene;
