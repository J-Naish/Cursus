/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 06:10:30 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 23:45:17 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	beat_game(t_game *game)
{
	ft_putstr_fd("You've beaten the game!!!\n", STDOUT_FILENO);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void	destroy_game(t_game *game)
{
	free(game->window);
	free(game->mlx);
	free(game->map);
}
