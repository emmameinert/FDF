/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:18:45 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:24:23 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fdf.h"

int	open_file(char **argv, t_lines *lines)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(lines);
		perror("error");
		exit(1);
	}
	return (fd);
}

void	scaling(t_lines *lines)
{
	if (!lines)
		exit(1);
	lines->scale = 1;
	if (lines->width < 15 || lines->length < 15)
		lines->scale = 40;
	else if ((lines->width >= 15 && lines->width <= 30)
		&& (lines->length >= 15 && lines->length <= 30))
		lines->scale = 30;
	else if ((lines->width >= 31 && lines->width <= 50)
		|| (lines->length >= 31 && lines->length <= 51))
		lines->scale = 15;
	else if ((lines->width >= 100 && lines->width < 150)
		|| (lines->length >= 100 && lines->length < 150))
		lines->scale = 7;
	else if ((lines->width >= 150 && lines->width <= 200)
		|| (lines->length >= 150 && lines->width <= 200))
		lines->scale = 5;
	else
		lines->scale = 3;
}

void	create_image(t_data *img, t_vars vars)
{
	img->img = mlx_new_image(vars.mlx, WIDTH, LENGTH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	main(int argc, char **argv)
{
	t_lines	*lines;
	t_vars	vars;
	t_data	*img;

	check_input(argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Emma's Fdf");
	lines = make_lines();
	count_lines(argv, lines);
	make_map(lines);
	passmylines(argv, lines);
	img = make_img();
	create_image(img, vars);
	lines->iso_map = make_iso_map(lines);
	fill_iso_map(&lines, img);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	free_the_things(img, lines);
	mlx_hook(vars.win, 17, 1L << 5, close_window, &vars);
	mlx_key_hook(vars.win, key_press_hook, &vars);
	mlx_loop(vars.mlx);
	if (vars.mlx)
		free(vars.mlx);
	if (vars.win)
		free(vars.win);
	return (0);
}
