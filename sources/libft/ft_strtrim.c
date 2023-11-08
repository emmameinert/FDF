/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:06:38 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/10 14:46:21 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*cpy;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) && (s1[i] != '\0'))
		i++;
	while ((ft_strchr(set, s1[len - 1])) && (len - 1 > 0))
		len--;
	j = 0;
	cpy = ft_substr(s1, i, len - i);
	return (cpy);
}
