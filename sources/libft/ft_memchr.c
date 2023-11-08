/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:13:49 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/03 14:42:43 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	d;
	size_t			i;

	ptr = (unsigned char *)str;
	d = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (ptr[i] != d && i < n && ptr[i] != '\0')
		i++;
	if (ptr[i] == d && i < n)
		return ((unsigned char *) &ptr[i]);
	else
		return (NULL);
}
