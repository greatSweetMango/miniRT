/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:04:49 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/04 19:55:47 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cc(void)
{
	system("leaks minirt");
}
int main(int argc, char **argv)
{
	atexit(&cc);
	t_scene *scene;
	
	scene = parse_arg(argc, argv);

	return (0);
}