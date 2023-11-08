# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 17:18:35 by emeinert          #+#    #+#              #
#    Updated: 2023/11/08 16:28:23 by emeinert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf ./sources/common/utils ./sources/graphics/graphics_utils ./sources/parsing/parsing ./sources/graphics/drawing ./sources/math/isometric ./sources/common/freeing ./sources/math/linearinterpol

HEADER = ./headers/fdf.h

CC = cc 

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

FILES = $(addsuffix .c,$(SRC))

OBJECTS = $(addsuffix .o,$(SRC))

LIBFT = ./sources/libft 

KEY = -lmlx -framework OpenGL -framework AppKit

MLX = ./mlx

all: $(NAME)

$(NAME): $(OBJECTS)
				make -C $(LIBFT)
				$(CC) $(FLAGS)  $(FILES) ./sources/libft/libft.a -L $(MLX) $(KEY) -o $@ 

clean:
				rm -f $(OBJECTS)
				cd $(LIBFT) && $(MAKE) clean

fclean: clean
				rm -f $(NAME)

re: fclean all