/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:13:45 by nash              #+#    #+#             */
/*   Updated: 2025/03/02 01:39:49 by nash             ###   ########.fr       */
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
