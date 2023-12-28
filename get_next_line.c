/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:26:41 by anthtorr          #+#    #+#             */
/*   Updated: 2023/12/22 16:26:09 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len && start < ft_strlen(s) && s[start])
		res[i] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*storage = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_lstclear(&storage);
		return (NULL);
	}
	if (!storage || !ft_strchr(storage, '\n'))
		storage = readbuf(fd, &storage);
	if (!storage)
		return (NULL);
	line = new_line(&storage);
	if (!line)
	{
		ft_lstclear(&storage);
		return (NULL);
	}
	storage = ft_lstclear(&storage);
	return (line);
}
