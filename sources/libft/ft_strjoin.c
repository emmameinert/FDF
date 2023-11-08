/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:06:26 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/10 15:10:53 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strnew;
	unsigned long	i;
	unsigned long	j;

	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && !s2)
		return (NULL);
	strnew = (char *)malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!strnew)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
		strnew[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
	strnew[i++] = s2[j++];
	strnew[i] = '\0';
	return (strnew);
}
