/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:33:10 by emeinert          #+#    #+#             */
/*   Updated: 2023/02/06 10:55:19 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_input(va_list args, char format)
{
	int	print_return;

	print_return = 0;
	if (format == 'c')
		print_return += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_return += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		print_return += ft_print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_return += ft_print_number(va_arg(args, int));
	else if (format == 'u')
		print_return += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X' )
		print_return += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_return += ft_print_percent();
	else
		print_return += ft_print_char(format);
	return (print_return);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	int			print_return;

	i = 0;
	print_return = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_return += ft_check_input(args, format[i]);
		}
		else
			print_return += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (print_return);
}
