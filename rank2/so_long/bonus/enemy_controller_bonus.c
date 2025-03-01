/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:13:45 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 03:19:42 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	spawn_enemy(t_game *game)
{
	int	i;
	int	x;
	int	y;

	game->enemy.move_count = 0;
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
		if (game->map[i] == '0')
		{
			game->enemy.pos.x = x;
			game->enemy.pos.y = y;
			game->map[i] = 'e';
			return ;
		}
		i++;
	}
}

static int	(*directions(void))[2]
{
	static int	directions[4][2];

	directions[0][0] = 0;
	directions[0][1] = -1;
	directions[1][0] = -1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = 1;
	directions[3][0] = 1;
	directions[3][1] = 0;
	return (directions);
}

void	move_enemy(t_game *game)
{
	int	dir_index;
	int	new_x;
	int	new_y;
	int	current_index;
	int	new_index;

	game->enemy.move_count += 1;
	dir_index = (game->enemy.move_count
			+ game->player.moves + game->player.collected_collectibles) % 4;
	new_x = game->enemy.pos.x + directions()[dir_index][0];
	new_y = game->enemy.pos.y + directions()[dir_index][1];
	current_index = game->enemy.pos.y * (game->width + 1) + game->enemy.pos.x;
	new_index = new_y * (game->width + 1) + new_x;
	if (new_x >= 0 && new_x < game->width && new_y >= 0
		&& new_y < game->height && game->map[new_index] != '1'
		&& game->map[new_index] != 'C' && game->map[new_index] != 'E')
	{
		game->map[current_index] = '0';
		game->map[new_index] = 'e';
		game->enemy.pos.x = new_x;
		game->enemy.pos.y = new_y;
	}
}
