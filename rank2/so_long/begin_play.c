/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:27:48 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 04:09:45 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(char c, t_game *game, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->empty,
			x * game->tile_size, y * game->tile_size);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall,
			x * game->tile_size, y * game->tile_size);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player,
			x * game->tile_size, y * game->tile_size);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectible,
			x * game->tile_size, y * game->tile_size);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit,
			x * game->tile_size, y * game->tile_size);
}

static void	load_images(t_game *game)
{
	int	width;
	int	height;

	width = game->tile_size;
	height = game->tile_size;
	game->empty = mlx_xpm_file_to_image(game->mlx, "./assets/background.xpm",
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./assets/block.xpm",
			&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "./assets/mario.xpm",
			&width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./assets/coin.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./assets/pipe.xpm",
			&width, &height);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	i;

	load_images(game);
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

static void	calculate_size(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = 0;
	while (game->map[i] != '\n')
	{
		width += 1;
		i++;
	}
	i = 0;
	height = 1;
	while (game->map[i])
	{
		if (game->map[i] == '\n')
			height += 1;
		i++;
	}
	game->width = width;
	game->height = height;
}

void	begin_play(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game->map);
		exit(EXIT_FAILURE);
	}
	calculate_size(game);
	game->tile_size = TILE_SIZE;
	game->window = mlx_new_window(game->mlx, game->width * game->tile_size,
			game->height * game->tile_size, "so_long");
	if (!game->window)
	{
		free(game->map);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	load_images(game);
	render_map(game);
}
