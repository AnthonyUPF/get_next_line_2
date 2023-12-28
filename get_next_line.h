/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:27:02 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/25 19:27:04 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
t_list		*ft_strchr(t_list *lst, int c);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
t_list		*ft_lstclear(t_list **lst);
t_list		*readbuf(int fd, t_list **storage);
char		*new_line(t_list **storage);
char		*ft_free(char **str);

#endif
