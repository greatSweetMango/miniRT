/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:21:27 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/06 18:44:19 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	objects_elements_check(t_scene *scene)
{
	if (!scene->ambient_lightning.is_set)
		puterr_exit("There is at least one Ambient Lights");
	else if (!scene->cameras)
		puterr_exit("There is at least one Camera!");
}

void	put2scene(t_scene *scene, char *line)
{
	char	**object;

	object = ft_split(line, WHITE_SPACE);
	if (object[0] != NULL)
		set_scene(scene, object);
	ft_split_free(object);
}

t_scene	*parse_arg(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;
	int		state;
	char	*line;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (argc != 2)
		puterr_exit("Arguments error! It has to (./minirt filename.rt)");
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
	objects_elements_check(scene);
	scene->selected_obj = scene->cameras;
	return (scene);
}
