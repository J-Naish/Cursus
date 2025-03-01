/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:13:45 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 02:38:15 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	spawn_enemy(t_game *game)
{
	int	i;
	int	x;
	int	y;

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

void	move_enemy(t_game *game)
{
	int			directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	int			dir_index;
	int			new_x, new_y;
	int			current_index, new_index;
	static int	move_count = 0;

	move_count++;
	dir_index = (move_count + game->player.moves + game->player.collected_collectibles) % 4;
	new_x = game->enemy.pos.x + directions[dir_index][0];
	new_y = game->enemy.pos.y + directions[dir_index][1];
	current_index = game->enemy.pos.y * (game->width + 1) + game->enemy.pos.x;
	new_index = new_y * (game->width + 1) + new_x;
	if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height &&
		game->map[new_index] != '1' && 
		game->map[new_index] != 'C' && 
		game->map[new_index] != 'E')
	{
		if (new_x == game->player.pos.x && new_y == game->player.pos.y)
		{
			ft_putstr_fd("Game Over! Enemy caught you!\n", STDOUT_FILENO);
			mlx_destroy_window(game->mlx, game->window);
			exit(EXIT_FAILURE);
		}
		game->map[current_index] = '0';
		game->map[new_index] = 'e';
		game->enemy.pos.x = new_x;
		game->enemy.pos.y = new_y;
	}
}
