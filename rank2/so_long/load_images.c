/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:33:41 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 03:46:41 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*read_wall(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/block.xpm", &width, &height));
}

static void	*read_player(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/mario.xpm", &width, &height));
}

static void	*read_collectible(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/coin.xpm", &width, &height));
}

static void	*read_exit(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/pipe.xpm", &width, &height));
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	width = game->tile_size;
	height = game->tile_size;
	game->wall = read_wall(game->mlx, width, height);
	game->player = read_player(game->mlx, width, height);
	game->collectible = read_collectible(game->mlx, width, height);
	game->exit = read_exit(game->exit, width, height);
}
