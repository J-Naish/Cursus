#include "../../include/cub3d.h"

void	debug_level(t_level *level)
{
	if (!level)
	{
		printf("Level: NULL\n");
		return ;
	}
	printf("=== Level Debug Info ===\n");
	printf("North texture: %s\n", level->n_texture_path);
	printf("South texture: %s\n", level->s_texture_path);
	printf("West texture: %s\n", level->w_texture_path);
	printf("East texture: %s\n", level->e_texture_path);
	printf("Floor color: \033[48;2;%d;%d;%dm    \033[0m R=%d, G=%d, B=%d\n",
		level->floor.r, level->floor.g, level->floor.b,
		level->floor.r, level->floor.g, level->floor.b);
	printf("Ceiling color: \033[48;2;%d;%d;%dm    \033[0m R=%d, G=%d, B=%d\n",
		level->ceiling.r, level->ceiling.g, level->ceiling.b,
		level->ceiling.r, level->ceiling.g, level->ceiling.b);
	debug_map(level->map);
	printf("========================\n");
}
