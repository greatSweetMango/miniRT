/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:05:36 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/04 17:35:20 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put2scene(t_scene *scene, char *line)
{
	char **object;

	object = ft_split(line, WHITE_SPACE);
	set_scene(scene, object);
}

t_scene	*parse_arg(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;
	int		state;
	char	*line;

	scene = ft_calloc(1, sizeof(t_scene));
	if (argc != 2)
		puterr_exit("Arguments error[ .rt (-save) ]");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		puterr_exit(strerror(errno));
	state = get_next_line(fd, &line);
	while (state != 0)
	{
		if (state < 0)
			puterr_exit(strerror(errno));
		put2scene(scene, line);
		free(line);
		state = get_next_line(fd, &line);
	}
	close(fd);
	free(scene);
	return (NULL);
}
