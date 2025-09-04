#include "../../include/cub3d.h"

void	render_frame(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		draw_floor_and_ceiling(game, x);
		cast_ray(&ray, &game->player, game->level->map, x);
		draw_vertical_line(game, x, &ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
}
