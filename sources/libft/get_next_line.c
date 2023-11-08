/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:35:39 by emeinert          #+#    #+#             */
/*   Updated: 2023/03/11 17:28:20 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_search_stash(char *stash)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	cpy = (char *) malloc((i + 2) * sizeof(char));
	if (!cpy)
		return (NULL);
	j = 0;
	while (j <= i && stash)
	{
		cpy[j] = stash[j];
		j++;
	}
	cpy[j] = '\0';
	if (cpy[0] == '\0')
	{
		free (cpy);
		return (NULL);
	}
	return (cpy);
}

static char	*ft_empty_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*empty_stash;

	len = ft_gnl_strlen(stash);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	empty_stash = (char *)malloc(((len - i) + 2) * sizeof(char));
	if (!empty_stash)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
		empty_stash[j++] = stash[i++];
	free (stash);
	empty_stash[j] = '\0';
	if (empty_stash[0] == '\0')
	{
		free (empty_stash);
		return (NULL);
	}
	return (empty_stash);
}

static char	*ft_read_input(int fd, char *stash)
{
	char		*buf;
	int			bytes;

	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buf[bytes] = '\0';
		if (!stash)
			stash = ft_make_stash();
		stash = ft_call_join(stash, buf);
		if (!stash)
			return (NULL);
		if (ft_gnl_strchr(buf, '\n'))
			break ;
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*return_line;
	static char	*stash;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = ft_read_input(fd, stash);
	if (!stash)
		return (NULL);
	return_line = ft_search_stash(stash);
	stash = ft_empty_stash(stash);
	return (return_line);
}
