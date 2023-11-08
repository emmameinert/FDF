/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearinterpol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:19:09 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:23:07 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	draw_diagonal_line_ver(int y, int ytemp, int x, t_data *img)
{
	if (ytemp > y)
	{
		while (ytemp > y)
		{
			my_mlx_pixel_put(img, x, ytemp, WHITE_PIXEL);
			ytemp--;
		}
	}
	else
	{
		while (ytemp <= y)
		{
			my_mlx_pixel_put(img, x, ytemp, WHITE_PIXEL);
			ytemp++;
		}
	}
}

void	draw_diagonal_line_hor(t_coord *p1, t_coord *p2, t_data *img, int flag)
{
	t_data	data;

	if (flag == 0)
	{
		data.y = p2->y_iso;
		data.x = p2->x_iso;
		data.xtemp = p1->x_iso;
	}
	else if (flag == 1)
	{
	data.x = p1->x_iso;
	data.y = p1->y_iso;
	data.xtemp = p2->x_iso;
	}
	while (data.x <= data.xtemp)
	{
		data.ytemp = data.y;
		data.y = linear_interpolation(p1, p2, data.x);
		draw_diagonal_line_ver(data.y, data.ytemp, data.x, img);
		my_mlx_pixel_put(img, data.x, data.y, WHITE_PIXEL);
		data.x++;
	}
}

int	linear_interpolation(t_coord *p1, t_coord *p2, int x)
{
	double	y;
	double	a;
	double	b;

	a = p1->y_iso * (p2->x_iso - x) + p2->y_iso * (x - p1->x_iso);
	b = (p2->x_iso - p1->x_iso);
	if (b == 0)
		exit(1);
	y = a / b;
	return (y);
}

void	draw_diagonal_line(t_coord *p1, t_coord *p2, t_data *img)
{
	if (p1->x_iso <= p2->x_iso)
		draw_diagonal_line_hor(p1, p2, img, 1);
	else if (p1->x_iso >= p2->x_iso)
		draw_diagonal_line_hor(p1, p2, img, 0);
}
