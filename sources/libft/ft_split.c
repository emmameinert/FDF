/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:06:50 by emeinert          #+#    #+#             */
/*   Updated: 2023/04/18 13:50:07 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	wordlen;

	i = 0;
	count = 0;
	wordlen = ft_strlen(s);
	while (i < wordlen)
	{	
		while (s[i] == c && i < wordlen)
			i++;
		if (i == wordlen)
			return (0);
		while (s[i] != c && i < wordlen)
			i++;
		count++;
		while (s[i] == c && i < wordlen)
			i++;
	}
	return (count);
}

static int	ft_make_str(char **str, size_t k, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (k < ft_count_words(s, c))
	{
		while ((s[i] == c) && (i < ft_strlen(s)))
			i++;
		j = i;
		while ((s[i] != c) && i < ft_strlen(s) && s[i] != '\0')
			i++;
		str[k] = ft_substr(s, j, (i - j));
		if (!str[k])
		{	
			while (k-- > 0)
				free(str[k]);
			return (0);
		}
		k++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	ft_make_str(str, 0, s, c);
	str[ft_count_words(s, c)] = NULL;
	return (str);
}
