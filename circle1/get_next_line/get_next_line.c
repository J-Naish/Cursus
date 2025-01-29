/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:54 by nash              #+#    #+#             */
/*   Updated: 2025/01/29 22:15:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_text(int fd, char *buffer)
{
	char	*text;
	ssize_t	bytes_read;

	text = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!text)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, text, BUFFER_SIZE * sizeof(char));
		if (bytes_read < 0)
		{
			free(text);
			return (NULL);
		}
		text[bytes_read] = '\0';
		buffer = ft_join_and_free(buffer, text);
		if (!buffer)
			return (NULL);
		if (ft_includes_newline(text))
			break ;
	}
	free(text);
	return (buffer);
}

static char	*ft_extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

static char	*ft_save_text(char *buffer)
{
	char	*save;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	save = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!save)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i + j])
	{
		save[j] = buffer[i + j];
		j++;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	buffer = ft_get_text(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	if (!line)
		return (NULL);
	buffer = ft_save_text(buffer);
	return (line);
}

// int	main()
// {
// 	int fd = open("test1.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open failed\n");
// 		return 1;
// 	}

// 	char *first_line = get_next_line(fd);
// 	printf("\nfirst line:\n %s\n", first_line);
//   free(first_line);

// 	char *second_line = get_next_line(fd);
// 	printf("second line:\n %s\n", second_line);
//   free(second_line);

// 	char *third_line = get_next_line(fd);
// 	printf("third line:\n %s\n", third_line);
//   free(third_line);

// 	close(fd);
// 	return (0);
// }
