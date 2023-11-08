/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:37:29 by emeinert          #+#    #+#             */
/*   Updated: 2023/02/06 10:55:15 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_unsigned_itoa(unsigned int n);
static int		ft_intlen(unsigned int nb);

int	ft_print_unsigned(unsigned int n)
{
	char	*number;
	int		length;

	number = ft_unsigned_itoa(n);
	length = ft_print_string(number);
	free(number);
	return (length);
}

static int	ft_intlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			len++;
		}
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = (long)n;
	len = ft_intlen(nb);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
