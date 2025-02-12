/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:21:26 by nash              #+#    #+#             */
/*   Updated: 2025/02/12 22:43:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join_free(char *buffer, char *text)
{
	char	*result;

	result = ft_strjoin(buffer, text);
	if (!result)
		return (free(buffer), free(text), NULL);
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
		line[i++] = '\n';
	return (line);
}

static char	*read_text(int fd, char *buffer)
{
	char	*text;
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	text = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_text(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = save_rest(buffer[fd]);
	return (line);
}

// int	main()
// {
// 	int fd1 = open("test1.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0)
// 	{
// 		perror("open failed\n");
// 		return 1;
// 	}
// 	while (1) {
// 		char *line = get_next_line(fd1);
// 		printf("%s\n", line);
// 		if (!line) {
// 			free(line);
// 			break;
// 		}
// 		free(line);
// 	}
// 	while (1) {
// 		char *line = get_next_line(fd2);
// 		printf("%s\n", line);
// 		if (!line) {
// 			free(line);
// 			break;
// 		}
// 		free(line);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }