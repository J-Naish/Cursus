#include "../../../include/cub3d.h"

static char	**init_map(char **map_lines)
{
	int		count;
	int		i;
	char	**map;

	count = 0;
	while (map_lines[count])
		count++;
	map = (char **)malloc((count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i <= count)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}

static char	*convert_line_to_symbols(char *map_line)
{
	char	*map_element;
	size_t	len;
	int		i;

	len = ft_strlen(map_line);
	map_element = (char *)ft_calloc((len + 1), sizeof(char));
	if (!map_element)
		return (NULL);
	i = 0;
	while (map_line[i])
	{
		map_element[i] = (char)map_line[i];
		i++;
	}
	return (map_element);
}

char	**get_map(char **map_lines)
{
	char	**map;
	int		i;

	map = init_map(map_lines);
	if (!map)
		return (NULL);
	i = 0;
	while (map_lines[i])
	{
		map[i] = convert_line_to_symbols(map_lines[i]);
		if (!map[i])
			return (free_strarr(map), NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}
