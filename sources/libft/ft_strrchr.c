/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:37:58 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/03 15:00:19 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if (s[len] == (char)c)
		return ((char *) &s[len]);
	else
	{
		while (s[len] != (char)c && len > 0)
			len--;
		if (s[len] == (char)c)
			return ((char *) &s[len]);
	}
	if (s[len] != (char)c && len == 0)
		return (NULL);
	return (NULL);
}
