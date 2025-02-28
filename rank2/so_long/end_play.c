/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:44:30 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 03:45:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_play(t_game *game)
{
	free(game->win);
	free(game->mlx);
	free(game->map);
}
