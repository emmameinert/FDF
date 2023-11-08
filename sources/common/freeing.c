/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:04:03 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:01 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	freemystuff(int **str, int length)
{
	int		i;

	i = length;
	if (str == NULL || str[0] == NULL)
		return ;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	freemystuffchar(char **str)
{
	int		i;
	char	*input;

	i = 0;
	if (str == NULL)
		exit(1);
	while (str[i])
	{
		input = str[i];
		free(input);
		i++;
	}
	free(str);
}

void	freemystuffcoord(t_coord **str, int length)
{
	int		i;

	i = 0;
	if (str == NULL)
		exit(1);
	while (i < length)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_the_things(t_data *img, t_lines *lines)
{
	if (lines->map)
		freemystuff(lines->map, lines->length - 1);
	if (lines->iso_map)
		freemystuffcoord(lines->iso_map, lines->length);
	if (lines)
		free(lines);
	if (img->img)
		free(img->img);
	if (img->addr)
		free(img->addr);
	if (img)
		free(img);
}
