/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:48:29 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:57 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	create_diagonal_line(int x, int y, t_lines **lines, t_data *img)
{
	t_coord	p1;
	t_coord	p2;
	t_coord	p3;

	p1 = (*lines)->iso_map[y][x];
	p2 = (*lines)->iso_map[y + 1][x];
	p3 = (*lines)->iso_map[y][x + 1];
	draw_diagonal_line(&p1, &p2, img);
	draw_diagonal_line(&p1, &p3, img);
}

void	create_diagonal_edge_line(int x, int y, t_lines **lines, t_data *img)
{
	t_coord	p1;
	t_coord	p2;

	if ((x == (*lines)->width - 1) && (y < (*lines)->length - 1))
	{
		p1 = (*lines)->iso_map[y][x];
		p2 = (*lines)->iso_map[y + 1][x];
		draw_diagonal_line(&p1, &p2, img);
	}
	else if (x < (*lines)->width - 1)
	{
		p1 = (*lines)->iso_map[y][x];
		p2 = (*lines)->iso_map[y][x + 1];
		draw_diagonal_line(&p1, &p2, img);
	}
}

void	draw_my_map(t_lines **lines, t_data *img)
{
	int	col;
	int	row;

	row = -1;
	while (++row < (*lines)->length - 1)
	{
		col = 0;
		while (col < (*lines)->width - 1)
		{
			create_diagonal_line(col, row, lines, img);
			col++;
			if ((col == (*lines)->width - 1) && (row < (*lines)->length - 1))
				create_diagonal_edge_line(col, row, lines, img);
		}
	}
	if (row == (*lines)->length - 1)
	{
		col = -1;
		while (++col < (*lines)->width - 1)
		{
			create_diagonal_edge_line(col, row, lines, img);
			if ((col == (*lines)->width - 1) && (row < (*lines)->length - 1))
				create_diagonal_edge_line(col, row, lines, img);
		}
	}
}
