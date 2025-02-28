/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:00:06 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 06:53:04 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_player(t_game *game)
{
	int	i;
	int	x;
	int	y;

	game->player.moves = 0;
	game->player.collected_collectibles = 0;
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
			game->player.pos.x = x;
			game->player.pos.y = y;
			return ;
		}
		i++;
	}
}

static int	on_collide(t_game *game, int new_index)
{
	if (game->map[new_index] == '1')
		return (0);
	else if (game->map[new_index] == 'E')
	{
		if (game->player.collected_collectibles < game->num_collectibles)
			return (0);
		beat_game(game);
	}
	else if (game->map[new_index] == 'C')
		game->player.collected_collectibles += 1;
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	current_index;
	int	new_index;

	new_x = game->player.pos.x + dx;
	new_y = game->player.pos.y + dy;
	current_index = game->player.pos.y
		* (game->width + 1) + game->player.pos.x;
	new_index = new_y * (game->width + 1) + new_x;
	if (on_collide(game, new_index) == 0)
		return ;
	game->map[current_index] = '0';
	game->map[new_index] = 'P';
	game->player.pos.x = new_x;
	game->player.pos.y = new_y;
	game->player.moves++;
	mlx_clear_window(game->mlx, game->window);
	print_movements(game->player.moves);
	render_map(game);
}
