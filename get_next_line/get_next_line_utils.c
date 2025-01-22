/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:57 by nash              #+#    #+#             */
/*   Updated: 2025/01/22 15:50:32 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_char__malloc(int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(2);
	if (!buffer)
	{
		return (NULL);
	}
	bytes_read = read(fd, buffer, 1);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[1] = '\0';
	return (buffer);
}

size_t	get_line_length(char *s)
{
	size_t	len;

	len = 0;
	while (*s && *s != '\n')
	{
		len++;
		s++;
	}
	return (len);
}
