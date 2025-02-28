/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:27:48 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 03:49:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	calculate_width(char *map)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (map[i] != '\n')
	{
		width += 1;
		i++;
	}
	return (width);
}

static int	calculate_height(char *map)
{
	int	i;
	int	height;

	i = 0;
	height = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			height += 1;
		i++;
	}
	return (height);
}

int	begin_play(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game->map), EXIT_FAILURE);
	game->width = calculate_width(game->map);
	game->height = calculate_height(game->map);
	game->tile_size = TILE_SIZE;
	game->win = mlx_new_window(game->mlx, game->width * game->tile_size,
			game->height * game->tile_size, "so_long");
	if (!game->win)
		return (free(game->map), free(game->mlx), EXIT_FAILURE);
	load_images(game);
	render_map(game);
	return (EXIT_SUCCESS);
}
