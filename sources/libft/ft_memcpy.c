/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:19:48 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/03 14:44:18 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;
	size_t			i;

	str = (unsigned char *)dst;
	ptr = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dst);
	if (str == NULL && ptr == NULL)
		return (dst);
	while (i < n)
	{
		str[i] = ptr[i];
		i++;
	}
	return (dst);
}
