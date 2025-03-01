/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_play_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:27:48 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 23:51:56 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	calculate_total_collectibles(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			count += 1;
		i++;
	}
	game->num_collectibles = count;
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
	calculate_total_collectibles(game);
	spawn_player(game);
	load_images(game);
	render_map(game);
}
