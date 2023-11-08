/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:17:22 by emeinert          #+#    #+#             */
/*   Updated: 2023/03/11 17:28:31 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_call_join(char *stash, char *buf)
{
	char	*join;

	join = ft_gnl_strjoin(stash, buf);
	if (!join)
		return (NULL);
	free(stash);
	return (join);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != d && s[i] != '\0')
			i++;
	if (s[i] == d)
		return ((char *) &s[i]);
	return (0);
}

char	*ft_gnl_strjoin(const char *s1, const char *s2)
{
	char			*strnew;
	unsigned long	i;
	unsigned long	j;
	size_t			len;

	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	strnew = (char *) malloc((len + 1) * sizeof(char));
	if (!strnew || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strnew[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strnew[i] = s2[j];
		i++;
		j++;
	}
	strnew[len] = '\0';
	return (strnew);
}

char	*ft_make_stash(void)
{
	char	*stash;

	stash = (char *) malloc (sizeof(char) * 1);
	if (!stash)
		return (NULL);
	*stash = '\0';
	return (stash);
}
