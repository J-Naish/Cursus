#include "../../include/cub3d.h"

int	game_loop(t_game *game)
{
	render_frame(game);
	return (0);
}

int	close_window(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	start_game(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
