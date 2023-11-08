/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:52:10 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/10 16:05:48 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (j < len
		&& haystack[j] != '\0')
	{
		while (haystack[j + i] == needle[i]
			&& needle[i] != '\0'
			&& j + i < len)
		{
			i++;
			if (needle[i] == '\0' && j + i <= len)
				return ((char *)&haystack[j]);
		}
			i = 0;
			j++;
	}
	return (NULL);
}
