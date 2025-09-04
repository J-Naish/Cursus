#include "../../include/cub3d.h"

char	*read_file(int fd)
{
	char	*line;
	char	*content;
	char	*temp;

	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	if (!content)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = content;
		content = ft_strjoin(content, line);
		free(temp);
		free(line);
		if (!content)
			return (NULL);
		line = get_next_line(fd);
	}
	return (content);
}
