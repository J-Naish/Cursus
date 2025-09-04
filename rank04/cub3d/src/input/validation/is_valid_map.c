#include "../../../include/cub3d.h"

static int	get_max_row(char **map_lines)
{
	int	max_row;

	max_row = 0;
	while (map_lines[max_row])
		max_row++;
	return (max_row);
}

static bool	is_valid_position(char **map_lines, int row, int col)
{
	int		max_row;
	int		len;
	int		adj_len;
	char	c;

	max_row = get_max_row(map_lines);
	if (row < 0 || row >= max_row)
		return (false);
	len = ft_strlen(map_lines[row]);
	if (col < 0 || col >= len)
		return (false);
	c = map_lines[row][col];
	if (is_empty(c) || is_player(c))
	{
		if (row == 0 || row == max_row - 1 || col == 0 || col == len - 1)
			return (false);
		adj_len = ft_strlen(map_lines[row - 1]);
		if (col >= adj_len)
			return (false);
		adj_len = ft_strlen(map_lines[row + 1]);
		if (col >= adj_len)
			return (false);
	}
	return (true);
}

bool	is_valid_map(char **map_lines)
{
	int	player_count;
	int	i;
	int	j;

	if (!map_lines || !map_lines[0])
		return (false);
	player_count = 0;
	i = 0;
	while (map_lines[i])
	{
		j = 0;
		while (map_lines[i][j])
		{
			if (is_player(map_lines[i][j]))
				player_count++;
			if (!is_valid_position(map_lines, i, j))
				return (false);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (false);
	return (true);
}
