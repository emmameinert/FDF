/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:41:24 by emeinert          #+#    #+#             */
/*   Updated: 2023/02/06 10:55:04 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_length(unsigned long number)
{
	int	length;

	length = 0;
	while (number != 0)
	{
		number = number / 16;
		length++;
	}
	return (length);
}

static void	ft_format(unsigned long number)
{
	if (number >= 16)
	{
		ft_format(number / 16);
		ft_format(number % 16);
	}
	else
	{
		if (number <= 9)
		{
			ft_putchar_fd(number + 48, 1);
		}
		else
		{
			ft_putchar_fd(number - 10 + 'a', 1);
		}
	}
}

int	ft_print_pointer(unsigned long pointer)
{
	int	print_return;

	print_return = 0;
	print_return = print_return + ft_print_string("0x");
	if (pointer == 0)
		print_return = print_return + ft_print_char('0');
	else
	{
		ft_format(pointer);
		print_return = print_return + ft_count_length(pointer);
	}
	return (print_return);
}
