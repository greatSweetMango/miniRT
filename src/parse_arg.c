/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:05:36 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/02 20:35:42 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*parse_arg(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	write(STDOUT, "PARSE DONE!!", ft_strlen("PARSE DONE!!"));

	return (NULL);
}