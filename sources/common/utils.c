/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:24:20 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:30 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

t_data	*make_img(void)
{
	t_data	*img;

	img = malloc(sizeof(t_data));
	if (!img)
		exit(1);
	return (img);
}

t_lines	*make_lines(void)
{
	t_lines	*lines;

	lines = malloc(sizeof(t_lines));
	if (!lines)
		exit(1);
	return (lines);
}

void	check_input(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("error: Unexpected number of arguments \n");
		exit(1);
	}
	len = ft_strlen(argv[1]) - 4;
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]) + 1) != &argv[1][len])
	{
		ft_printf("error: not a *.fdf file\n");
		exit(1);
	}
}
