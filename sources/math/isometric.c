/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:09:46 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:23:05 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	isometric_coordinates(int x, int y, int z, t_lines **lines)
{
	double	xcoord;
	double	ycoord;
	int		alt;
	int		a;
	int		b;

	a = (WIDTH / 2) - (*lines)->scale / 4 * (*lines)->width / 4;
	b = (LENGTH / 2) - (*lines)->scale / 2 * (*lines)->length / 2;
	z = z * 4;
	alt = (y * (*lines)->scale / 2 - z) * cos(M_PI / 3);
	xcoord = ((*lines)->scale) * (cos(M_PI / 3) * x - sin(M_PI / 6) * y) + a;
	ycoord = ((*lines)->scale / 2) * ((sin(M_PI / 6) * x)) + alt + b;
	(*lines)->iso_map[y][x] = (t_coord){xcoord, ycoord};
}

void	fill_iso_map(t_lines **lines, t_data *img)
{
	int	i;
	int	j;
	int	z;

	j = 0;
	scaling((*lines));
	while (j < (*lines)->length)
	{
		i = 0;
		while (i < (*lines)->width)
		{
			z = (*lines)->map[j][i];
			isometric_coordinates(i, j, z, lines);
			i++;
		}
		j++;
	}
	draw_my_map(lines, img);
}

t_coord	**make_iso_map(t_lines *lines)
{
	int	j;

	j = 0;
	lines->iso_map = ft_calloc(sizeof(int *), (lines->length));
	if (!lines->iso_map)
	{
		freemystuff(lines->map, lines->length - 1);
		free(lines);
		exit(1);
	}
	while (j < lines->length)
	{
		lines->iso_map[j] = ft_calloc(sizeof(t_coord), (lines->width));
		if (!lines->iso_map[j])
		{
			freemystuffcoord(lines->iso_map, j + 1);
			freemystuff(lines->map, lines->length - 1);
			free(lines);
			exit(1);
		}
		j++;
	}
	return (lines->iso_map);
}
