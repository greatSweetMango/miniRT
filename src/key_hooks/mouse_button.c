/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:02:35 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/19 20:15:46 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_button(int btn, int x, int y, void *param)
{
	(void)param;
	printf("\nBTN: %d\nPOS: (%d, %d)\n", btn, x, y);
	return (0);
}
