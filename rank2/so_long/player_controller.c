/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:00:06 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 06:17:15 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_player(t_game *game)
{
	int	i;
	int	x;
	int	y;

	game->player_pos.moves = 0;
	i = 0;
	y = 0;
	while (game->map[i])
	{
		if (game->map[i] == '\n')
		{
			y += 1;
			i++;
			continue ;
		}
		x = i % (game->width + 1);
		if (game->map[i] == 'P')
		{
			game->player_pos.x = x;
			game->player_pos.y = y;
			return ;
		}
		i++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	current_index;
	int	new_index;

	new_x = game->player_pos.x + dx;
	new_y = game->player_pos.y + dy;
	current_index = game->player_pos.y
		* (game->width + 1) + game->player_pos.x;
	new_index = new_y * (game->width + 1) + new_x;
	if (game->map[new_index] == '1')
		return ;
	else if (game->map[new_index] == 'E')
		beat_game(game);
	game->map[current_index] = '0';
	game->map[new_index] = 'P';
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	game->player_pos.moves++;
	mlx_clear_window(game->mlx, game->window);
	print_movements(game->player_pos.moves);
	render_map(game);
}
