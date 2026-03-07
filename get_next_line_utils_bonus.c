/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchibukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:37:45 by kchibukh          #+#    #+#             */
/*   Updated: 2026/03/04 20:55:27 by kchibukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int i)
{
	while (*str)
	{
		if (*str == (char)i)
			return ((char *)str);
		str++;
	}
	if (*str == (char)i)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen(src);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *l1, const char *l2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!l1 || !l2)
		return (NULL);
	i = 0;
	j = 0;
	new = (char *)malloc(ft_strlen(l1) + ft_strlen(l2) + 1);
	if (!new)
		return (NULL);
	while (l1[i] != '\0')
	{
		new[i] = l1[i];
		i++;
	}
	while (l2[j] != '\0')
	{
		new[i + j] = l2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
