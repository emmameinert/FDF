/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:47:54 by emeinert          #+#    #+#             */
/*   Updated: 2023/02/06 10:54:55 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_length(unsigned long number)
{
	int	length;

	length = 0;
	while (number != 0)
	{
		length++;
		number = number / 16;
	}
	return (length);
}

static int	ft_format(unsigned long number, char format)
{
	int	i;

	i = 0;
	if (number >= 16)
	{
		ft_format(number / 16, format);
		ft_format(number % 16, format);
	}
	if (number <= 15 && number >= 10)
	{
		if (format == 'x')
			ft_putchar_fd(number - 10 + 'a', 1);
		else if (format == 'X')
			ft_putchar_fd(number - 10 + 'A', 1);
	}
	if (number <= 9 && number >= 0)
	{
		ft_putchar_fd(number + 48, 1);
	}
	return (i);
}

int	ft_print_hexa(unsigned long number, char format)
{
	int	print_return;

	print_return = 0;
	if (number == 0)
	{	
		write (1, "0", 1);
		return (1);
	}
	else if (number > 0)
		ft_format(number, format);
	print_return += ft_count_length(number);
	return (print_return);
}
