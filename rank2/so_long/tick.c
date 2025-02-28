/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:42:29 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 04:48:23 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	on_press_escape(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	tick(t_game *game)
{
	mlx_key_hook(game->window, on_press_escape, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
