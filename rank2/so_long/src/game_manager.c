/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 06:10:30 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 21:32:06 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	beat_game(t_game *game)
{
	ft_putstr_fd("You've beaten the game!!!\n", STDOUT_FILENO);
	destroy_game(game);
	exit(EXIT_SUCCESS);
}

static void	destroy_images(t_game *game)
{
	if (game->images.empty)
		mlx_destroy_image(game->mlx, game->images.empty);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	if (game->images.collectible)
		mlx_destroy_image(game->mlx, game->images.collectible);
	if (game->images.player)
		mlx_destroy_image(game->mlx, game->images.player);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
}

void	destroy_game(t_game *game)
{
	destroy_images(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	free(game->map);
}
