/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:20:43 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 09:27:10 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*get_content(int fd)
{
	char	*line;
	char	*map;
	char	*temp;

	map = ft_calloc(1, sizeof(char));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map;
		map = ft_strjoin(map, line);
		free(temp);
		free(line);
		if (!map)
			return (NULL);
	}
	return (map);
}

char	*read_map(const char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		arg_error(strerror(errno));
	content = get_content(fd);
	close(fd);
	return (content);
}
