/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:53:28 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/02/14 19:06:14 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* File descripter */
#define STDIN	0
#define STDOUT	1
#define STDERR	2

#define WHITE_SPACE	"\n\t\v\f\r "
#define PI			3.141592

/* COLOR */
#define RGB_MAX 255

/* Image info */
#define WIN_WIDTH		700
#define WIN_HEIGHT		700
#define CONSOLE_WIDTH	200

/* Key value */
#define KEY_ESC		53

#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define KEY_W			13
#define KEY_R			15
#define KEY_F			3
#define	MOVE_RATIO		20

#define KEY_LEFT	123 //Arrow Key
#define KEY_RIGHT	124 //Arrow Key
#define KEY_DOWN	125 //Arrow Key
#define KEY_UP		126 //Arrow Key
#define ROTATE_RATIO	3 //degree

#define KEY_PREV	43	//(<)
#define KEY_NEXT	47	//(>)
#define KEY_SPACEBAR	49

/* Object type */
#define CAMERA		0
#define LIGHT		1
#define SPHERE		2
#define PLANE		3
#define CYLINDER	4
#define CONE		5 // BONUS
#define HYPERBOLOID 6 // BONUS
#define PARABOLOID	7 // BONUS
