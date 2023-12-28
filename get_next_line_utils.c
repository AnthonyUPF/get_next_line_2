/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:28:38 by anthtorr          #+#    #+#             */
/*   Updated: 2023/12/22 16:28:38 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

t_list	*ft_strchr(t_list *lst, int c)
{
	char	*content;

	while (lst)
	{
		content = lst->content;
		while (*content)
		{
			if (*content == (char)c)
				return (lst);
			content++;
		}
		lst = lst->next;
	}
	return (NULL);
}

t_list	*clean_storage(t_list **storage)
{
	t_list	*new_storage;
	t_list	*ptr;
	size_t	len;

	ptr = ft_strchr(*storage, '\n');
	if (!ptr)
		return (ft_lstclear(storage));
	len = (ptr->content - (*storage)->content) + 1;
	if (!ptr->next)
	{
		new_storage = ft_substr((*storage)->content, len, ft_strlen((*storage)->content) - len);
		ft_lstclear(storage);
		return (new_storage);
	}
	new_storage = ft_substr(ptr->content, 1, ft_strlen(ptr->content) - 1);
	ft_lstclear(storage);
	return (new_storage);
}

t_list	*readbuf(int fd, t_list **storage)
{
	int		rid;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_lstclear(storage));
	buffer[0] = '\0';
	rid = 1;
	while (rid > 0 && !ft_strchr(*storage, '\n'))
	{
		rid = read(fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			*storage = ft_strjoin(*storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_lstclear(storage));
	return (*storage);
}

char	*new_line(t_list **storage)
{
	t_list	*ptr;
	char	*line;
	size_t	len;

	ptr = ft_strchr(*storage, '\n');
	len = (ptr->content - (*storage)->content) + 1;
	line = ft_substr((*storage)->content, 0, len);
	return (line);
}

t_list	*ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
	return (NULL);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
