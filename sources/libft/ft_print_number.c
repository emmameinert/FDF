/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:46:54 by emeinert          #+#    #+#             */
/*   Updated: 2023/02/06 10:54:58 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_number(int n)
{
	char	*number;
	int		length;

	number = ft_itoa(n);
	length = ft_print_string(number);
	free (number);
	return (length);
}
