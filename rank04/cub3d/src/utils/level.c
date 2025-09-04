#include "../../include/cub3d.h"

void	free_level(t_level *level)
{
	if (!level)
		return ;
	if (level->n_texture_path)
		free(level->n_texture_path);
	if (level->s_texture_path)
		free(level->s_texture_path);
	if (level->w_texture_path)
		free(level->w_texture_path);
	if (level->e_texture_path)
		free(level->e_texture_path);
	if (level->map)
		free_strarr(level->map);
	free(level);
}
