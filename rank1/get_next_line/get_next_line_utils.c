/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:46:46 by nash              #+#    #+#             */
/*   Updated: 2025/02/12 22:34:08 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*result;
	int		i;
	int		j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total_size + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[total_size] = 0;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	if (!s)
		return ;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == 0 || size == 0)
		return ((void *)malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	result = (void *)malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, (count * size));
	return (result);
}
