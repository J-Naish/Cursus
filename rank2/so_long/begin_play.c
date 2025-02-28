/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:27:48 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 05:29:23 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	spawn_player(game);
	load_images(game);
	render_map(game);
}
