/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:42:29 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 02:38:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	on_key_press(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 0 || keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 2 || keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

static int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	update_animation(t_game *game)
{
	static int	enemy_move_counter = 0;

	game->frame_counter++;
	if (game->frame_counter >= game->animation_speed)
	{
		game->frame_counter = 0;
		game->current_frame = (game->current_frame + 1) % ANIMATION_FRAMES;
		render_map(game);
	}
	enemy_move_counter++;
	if (enemy_move_counter >= 30)
	{
		move_enemy(game);
		enemy_move_counter = 0;
		render_map(game);
	}
	return (0);
}

void	tick(t_game *game)
{
	mlx_key_hook(game->window, on_key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, update_animation, game);
	mlx_loop(game->mlx);
}
