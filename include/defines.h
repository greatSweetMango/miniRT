/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:53:28 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/04/05 12:28:50 by jaehyuki         ###   ########.fr       */
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
#define WIN_WIDTH			900
#define WIN_HEIGHT			900
#define CONSOLE_WIDTH		200

/* TEXTURE_TYPE */
#define TT_NONE 0
#define TT_CHECKER 1
#define TT_IMAGE 2

/* Bonus */
#define	NUM_THREAD		10
#define WIDTH_BLOCK		WIN_WIDTH / NUM_THREAD
#define HEIGHT_BLOCK	WIN_HEIGHT / NUM_THREAD

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
#define ROTATE_RATIO	10 //degree

#define KEY_PREV	    43	//(<)
#define KEY_NEXT	    47	//(>)
#define KEY_SPACEBAR	49
#define KEY_LIGHT       37

#define KEY_DIAMETER_DOWN   27 //(=)
#define KEY_DIAMETER_UP     24 //(-)
#define KEY_HEIGHT_DOWN     33 //([)
#define KEY_HEIGHT_UP       30 //(])
#define RESIZE_RATIO        3

/* Object type */
#define CAMERA		0
#define LIGHT		1
#define SPHERE		2
#define PLANE		3
#define CYLINDER	4
#define CONE		5 // BONUS
