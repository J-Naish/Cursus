/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 06:10:30 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 06:15:37 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	beat_game(t_game *game)
{
	ft_putstr_fd("You've beaten the game!!!\n", STDOUT_FILENO);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}
