#include "../../include/cub3d.h"

t_game	*init_game(t_level *level)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (free_level(level), NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), free_level(level), NULL);
	game->window
		= mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!game->window)
		return (free(game->mlx), free(game), free_level(level), NULL);
	game->level = level;
	init_player(&game->player, level);
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.img)
		return (mlx_destroy_window(game->mlx, game->window),
			free(game->mlx), free(game), free_level(level), NULL);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!load_textures(game))
		return (mlx_destroy_image(game->mlx, game->img.img),
			mlx_destroy_window(game->mlx, game->window),
			free(game->mlx), free(game), free_level(level), NULL);
	return (game);
}

void	destroy_game(t_game *game)
{
	destroy_textures(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->window);
	// mlx_destroy_display(game->mlx);
	free_level(game->level);
	free(game->mlx);
	free(game);
}
