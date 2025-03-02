/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:12:42 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 07:31:33 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(char c, t_game *game, int x, int y)
{
	if (c == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.empty, x * game->tile_size, y * game->tile_size);
	else if (c == WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.wall, x * game->tile_size, y * game->tile_size);
	else if (c == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.player, x * game->tile_size, y * game->tile_size);
	else if (c == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.collectible, x * game->tile_size, y * game->tile_size);
	else if (c == EXIT)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.exit, x * game->tile_size, y * game->tile_size);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		if (game->map[i] == '\n')
		{
			y++;
			x = 0;
			i++;
			continue ;
		}
		x = i % (game->width + 1);
		put_image(game->map[i], game, x, y);
		i++;
	}
}
