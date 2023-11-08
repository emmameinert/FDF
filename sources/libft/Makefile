# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 14:41:36 by emeinert          #+#    #+#              #
#    Updated: 2023/03/11 13:18:40 by emeinert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi \
	  ft_bzero \
	  ft_calloc \
	  ft_isalnum \
	  ft_isalpha \
	  ft_isascii \
	  ft_isdigit \
	  ft_isprint \
	  ft_memchr \
	  ft_memcmp \
	  ft_memcpy \
	  ft_memmove \
	  ft_memset \
	  ft_strchr \
	  ft_strdup \
	  ft_strlcat \
	  ft_strlcpy \
	  ft_strlen \
	  ft_strncmp \
	  ft_strnstr \
	  ft_strrchr \
	  ft_tolower \
	  ft_toupper \
	  ft_strjoin \
	  ft_substr \
	  ft_strmapi \
	  ft_putendl_fd \
	  ft_putstr_fd \
	  ft_putnbr_fd \
	  ft_putchar_fd \
	  ft_striteri \
	  ft_strtrim \
	  ft_split \
	  ft_split_n \
	  ft_itoa \
	  get_next_line_utils \
	  get_next_line \
	  ft_print_char \
	  ft_print_hexa \
	  ft_print_number \
	  ft_print_percent \
	  ft_print_string \
	  ft_print_pointer \
	  ft_print_udecimal \
	  ft_printf

HEADAER = libft.h

FILES = $(addsuffix .c,$(SRC))

OBJECT = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(FILES)
		cc -Wall -Wextra -Werror $(FILES) -c -I $(HEADER)
		ar rc $(NAME) $(OBJECT) 

clean:
		rm -f $(OBJECT)

fclean: clean
		rm -f $(NAME)

re: fclean all
