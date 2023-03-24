/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:30:02 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/03/24 16:58:08 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_file_check(const char *filename)
{
	int		fd;
	char	*err_str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		err_str = ft_strjoin("File open fail : ", filename);
		puterr_exit(err_str);
	}
	close(fd);
}
