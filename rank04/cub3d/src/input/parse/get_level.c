#include "../../../include/cub3d.h"

static t_level	*init_level(void)
{
	t_level	*level;

	level = (t_level *)malloc(sizeof(t_level));
	if (!level)
		return (NULL);
	level->n_texture_path = NULL;
	level->s_texture_path = NULL;
	level->e_texture_path = NULL;
	level->w_texture_path = NULL;
	level->map = NULL;
	return (level);
}

static char	*extract_texture_path(char **lines, char *identifier)
{
	int		index;
	char	*line;
	char	*path;

	index = get_identifier_index(lines, identifier);
	if (index == -1)
		return (NULL);
	line = lines[index];
	line += ft_strlen(identifier);
	path = ft_strdup(line);
	return (path);
}

static t_color	extract_color(char **lines, char *identifier)
{
	int		index;
	char	*line;

	index = get_identifier_index(lines, identifier);
	if (index == -1)
		return ((t_color){0, 0, 0});
	line = lines[index];
	line += ft_strlen(identifier);
	return (get_color(line));
}

static bool	guard_level(t_level *level)
{
	if (!level->n_texture_path)
		return (free_level(level), true);
	if (!level->s_texture_path)
		return (free_level(level), true);
	if (!level->e_texture_path)
		return (free_level(level), true);
	if (!level->w_texture_path)
		return (free_level(level), true);
	if (!level->map)
		return (free_level(level), true);
	return (false);
}

t_level	*get_level(char *content)
{
	t_level	*level;
	char	**lines;
	char	**map_lines;

	level = init_level();
	if (!level)
		return (NULL);
	lines = get_lines(content);
	if (!lines)
		return (free_level(level), NULL);
	level->n_texture_path = extract_texture_path(lines, "NO ");
	level->s_texture_path = extract_texture_path(lines, "SO ");
	level->w_texture_path = extract_texture_path(lines, "WE ");
	level->e_texture_path = extract_texture_path(lines, "EA ");
	level->floor = extract_color(lines, "F ");
	level->ceiling = extract_color(lines, "C ");
	map_lines = extract_map_lines(lines);
	if (!map_lines)
		return (free_level(level), NULL);
	free_strarr(lines);
	level->map = get_map(map_lines);
	free_strarr(map_lines);
	if (guard_level(level))
		return (NULL);
	return (level);
}
