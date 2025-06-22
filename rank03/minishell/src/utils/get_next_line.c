/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:59 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:59 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static char	*join_free(char *buffer, char *text)
{
	char	*result;

	result = ft_strjoin(buffer, text);
	if (!result)
		return (free(buffer), NULL);
	free(buffer);
	return (result);
}

static char	*save_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	rest = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!rest)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	free(buffer);
	return (rest);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*read_text(int fd, char *buffer)
{
	char	*text;
	int		bytes_read;

	text = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!text)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(text), free(buffer), NULL);
		text[bytes_read] = '\0';
		buffer = join_free(buffer, text);
		if (!buffer)
			return (free(text), NULL);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(text);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	buffer = read_text(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = save_rest(buffer);
	return (line);
}

// int main() {
// 	int fd = open("Makefile", O_RDONLY);
// 	while (1)
// 	{
// 		char *line = get_next_line(fd);
// 		if (!line) {
// 			free(line);
// 			break;
// 		}
// 		ft_putstr_fd(line, STDOUT_FILENO);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }