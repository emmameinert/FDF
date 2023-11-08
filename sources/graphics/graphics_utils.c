/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:05:29 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:58 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	key_press_hook(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		close_window(vars);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
	{
		offset = y * data->line_length + x * (data->bits_per_pixel / 8);
		dst = data->addr + offset;
		*(unsigned int *) dst = color;
	}
}
