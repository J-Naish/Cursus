#include "../../include/cub3d.h"

static bool	load_texture(void *mlx, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (false);
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel,
			&texture->line_length,
			&texture->endian);
	return (true);
}

bool	load_textures(t_game *game)
{
	if (!load_texture(game->mlx, &game->textures[0],
			game->level->n_texture_path))
		return (false);
	if (!load_texture(game->mlx, &game->textures[1],
			game->level->s_texture_path))
	{
		mlx_destroy_image(game->mlx, game->textures[0].img);
		return (false);
	}
	if (!load_texture(game->mlx, &game->textures[2],
			game->level->e_texture_path))
	{
		mlx_destroy_image(game->mlx, game->textures[0].img);
		mlx_destroy_image(game->mlx, game->textures[1].img);
		return (false);
	}
	if (!load_texture(game->mlx, &game->textures[3],
			game->level->w_texture_path))
	{
		mlx_destroy_image(game->mlx, game->textures[0].img);
		mlx_destroy_image(game->mlx, game->textures[1].img);
		mlx_destroy_image(game->mlx, game->textures[2].img);
		return (false);
	}
	return (true);
}

void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
}
