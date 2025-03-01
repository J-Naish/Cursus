/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 06:10:30 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 01:06:00 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	beat_game(t_game *game)
{
	ft_putstr_fd("You've beaten the game!!!\n", STDOUT_FILENO);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void	destroy_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images.empty);
	mlx_destroy_image(game->mlx, game->images.wall);
	mlx_destroy_image(game->mlx, game->images.player);
	mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.collectible)
	{
		mlx_destroy_image(game->mlx, game->images.collectible[0]);
		mlx_destroy_image(game->mlx, game->images.collectible[1]);
		mlx_destroy_image(game->mlx, game->images.collectible[2]);
	}
	free(game->images.collectible);
	free(game->window);
	free(game->mlx);
	free(game->map);
}
