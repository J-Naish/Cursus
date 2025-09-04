#include "../../../include/cub3d.h"

bool	includes_valid_map(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
			return (true);
		i++;
	}
	return (false);
}
