/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:29:01 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:24:09 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

char	**cut_lines(char *str, t_lines *lines)
{
	char	**cut_line;

	cut_line = ft_split(str, ' ');
	if (!cut_line)
	{
		if (lines->map)
			freemystuff(lines->map, lines->length - 1);
		free(lines);
		exit(1);
	}
	return (cut_line);
}

void	count_columns(char **columns, t_lines *lines)
{
	lines->width = 0;
	if (columns)
	{
		while (columns[lines->width] != NULL)
			lines->width++;
		if (columns[lines->width - 1][0] == '\n')
			lines->width = lines->width - 1;
	}
	else
		exit(1);
}

void	count_lines(char **argv, t_lines *lines)
{
	char	*str;

	lines->length = 1;
	lines->fd = open_file(argv, lines);
	str = get_next_line(lines->fd);
	if (!str)
	{
		perror("error");
		exit(1);
	}
	lines->columns = cut_lines(str, lines);
	count_columns(lines->columns, lines);
	freemystuffchar(lines->columns);
	while (42)
	{
		free(str);
		str = get_next_line(lines->fd);
		if (!str)
			break ;
		lines->length++;
	}
	if (close(lines->fd) < 0)
		perror("error");
	if (str)
		free(str);
}

void	make_map(t_lines *lines)
{
	int	j;

	j = 0;
	lines->map = ft_calloc(sizeof(int *), (lines->length));
	if (!lines->map)
	{
		free(lines);
		exit(1);
	}
	while (j < lines->length)
	{
		lines->map[j] = ft_calloc(sizeof(int ), (lines->width));
		if (!lines->map[j])
		{
			freemystuff(lines->map, j);
			exit(1);
		}
		j++;
	}
}

void	passmylines(char **argv, t_lines *lines)
{
	int		i;
	int		j;
	char	**cut_line;

	i = 0;
	lines->fd = open_file(argv, lines);
	while (i < lines->length)
	{
		j = 0;
		i++;
		if (i <= lines->length)
			lines->line = get_next_line(lines->fd);
		cut_line = cut_lines(lines->line, lines);
		free(lines->line);
		while (j < lines->width)
		{
			lines->map[i - 1][j] = ft_atoi(cut_line[j]);
			j++;
		}
		freemystuffchar(cut_line);
	}
	if (close(lines->fd) < 0)
		perror("error");
}
