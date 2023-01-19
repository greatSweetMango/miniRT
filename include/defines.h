/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:53:28 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/19 20:15:46 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* File descripter */
#define STDIN	0
#define STDOUT	1
#define STDERR	2

#define WHITE_SPACE	"\n\t\v\f\r "

/* COLOR */
#define RGB_MAX 255

/* Image info */
#define WIN_WIDTH		700
#define WIN_HEIGHT		700
#define CONSOLE_WIDTH	200

/* Key value */
#define KEY_ESC 53

/* Object type */
#define CAMERA		0
#define LIGHT		1
#define SPHERE		2
#define PLANE		3
#define CYLINDER	4
#define CONE		5 // BONUS
#define HYPERBOLOID 6 // BONUS
#define PARABOLOID	7 // BONUS
