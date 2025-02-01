/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:57 by nash              #+#    #+#             */
/*   Updated: 2025/02/01 15:37:56 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_join_and_free(char *buffer, char *text)
{
	char	*result;

	if (!buffer)
		return (NULL);
	result = ft_strjoin(buffer, text);
	if (!result)
		return (NULL);
	free(buffer);
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	if (count == 0 || size == 0)
		return ((void *)malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	result = (void *)malloc(count * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)result)[i] = 0;
		i++;
	}
	return (result);
}

bool	ft_includes_newline(char *s)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (*s == '\n')
			return (true);
		s++;
	}
	return (false);
}
