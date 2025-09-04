#include "../../include/cub3d.h"

void	debug_map(char **map)
{
	int	i;
	int	j;

	if (!map)
	{
		printf("Map: NULL\n");
		return ;
	}
	printf("Map:\n");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			printf("%c", (char)map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
