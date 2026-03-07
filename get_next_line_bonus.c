/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchibukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:33:04 by kchibukh          #+#    #+#             */
/*   Updated: 2026/03/05 18:50:35 by kchibukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_ptr(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

static ssize_t	ft_read_line(int fd, char **buffer)
{
	char	*temp;
	ssize_t	bytes_read;
	char	*new_buffer;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (-1);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(temp);
		free_ptr(buffer);
		return (-1);
	}
	temp[bytes_read] = '\0';
	new_buffer = ft_strjoin(*buffer, temp);
	free(temp);
	if (!new_buffer)
		return (-1);
	free_ptr(buffer);
	*buffer = new_buffer;
	return (bytes_read);
}

static char	*extract_line(char **buffer, char *nl_pos)
{
	char	*l;
	char	*temp;

	l = ft_substr(*buffer, 0, nl_pos - *buffer + 1);
	if (!l)
		return (NULL);
	temp = ft_strdup(nl_pos + 1);
	if (!temp)
	{
		free(l);
		free_ptr(buffer);
		return (NULL);
	}
	free_ptr(buffer);
	*buffer = temp;
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*nl_pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	while (1)
	{
		nl_pos = ft_strchr(stash[fd], '\n');
		if (nl_pos)
			return (extract_line(&stash[fd], nl_pos));
		if (ft_read_line(fd, &stash[fd]) <= 0)
			break ;
	}
	if (stash[fd] && *stash[fd])
	{
		line = ft_strdup(stash[fd]);
		free_ptr(&stash[fd]);
		return (line);
	}
	free_ptr(&stash[fd]);
	return (NULL);
}
