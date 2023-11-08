/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:41:45 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 16:27:52 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../sources/libft/libft.h"
# include "../mlx/mlx.h"
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define KEY_ESC	53
# define WIDTH 1920
# define LENGTH 1080

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			xtemp;
	int			ytemp;
	int			x;
	int			y;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coord {
	double	x_iso;
	double	y_iso;
}		t_coord;

typedef struct s_lines{
	char		*line;
	char		**columns;
	int			**map;
	t_coord		**iso_map;
	int			fd;
	int			width;
	int			length;
	int			scale;
}		t_lines;

t_data	*make_img(void);
t_lines	*make_lines(void);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	check_input(int argc, char **argv);
void	count_lines(char **argv, t_lines *lines);

//freeedom
void	freemystuffchar(char **str);
void	freemystuffcoord(t_coord **str, int length);
void	free_the_things(t_data *img, t_lines *lines);
void	freemystuff(int **str, int length);

//window

int		close_window(t_vars *vars);
int		key_press_hook(int key, t_vars *vars);
void	create_image(t_data *img, t_vars vars);
void	scaling(t_lines *lines);

//parsing

int		open_file(char **argv, t_lines *lines);
void	count_lines(char **argv, t_lines *lines);
char	**cut_lines(char *str, t_lines *lines);
void	count_columns(char **columns, t_lines *lines);
void	make_map(t_lines *lines);
void	passmylines(char **argv, t_lines *lines);

//isometric

void	isometric_coordinates(int x, int y, int z, t_lines **lines);
void	fill_iso_map(t_lines **lines, t_data *img);
t_coord	**make_iso_map(t_lines *lines);

//drawing map

void	draw_my_map(t_lines **lines, t_data *img);
int		linear_interpolation(t_coord *p1, t_coord *p2, int x);
void	create_diagonal_line(int x, int y, t_lines **lines, t_data *img);
void	draw_diagonal_line_hor(t_coord *p1, t_coord *p2, t_data *img, int flag);
void	draw_diagonal_line(t_coord *p1, t_coord *p2, t_data *img);
void	draw_diagonal_line_ver(int y, int ytemp, int x, t_data *img);
void	create_diagonal_edge_line(int x, int y, t_lines **lines, t_data *img);

#endif
