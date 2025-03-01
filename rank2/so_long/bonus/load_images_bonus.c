/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:14:11 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 01:06:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	width = game->tile_size;
	height = game->tile_size;
	game->images.empty = mlx_xpm_file_to_image(game->mlx,
			"./assets/background.xpm", &width, &height);
	game->images.wall = mlx_xpm_file_to_image(game->mlx,
			"./assets/block.xpm", &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx,
			"./assets/mario.xpm", &width, &height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx,
			"./assets/pipe.xpm", &width, &height);
	game->images.collectible = malloc(sizeof(void *) * 3);
	if (!game->images.collectible)
	{
		destroy_game(game);
		exit(EXIT_FAILURE);
	}
	game->images.collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/coin1.xpm", &width, &height);
	game->images.collectible[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/coin2.xpm", &width, &height);
	game->images.collectible[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/coin3.xpm", &width, &height);
}
