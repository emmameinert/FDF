/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:47:04 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/04 14:48:37 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;
	size_t			i;

	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] != ptr[i])
			return (str[i] - ptr[i]);
		i++;
	}
	return (0);
}
