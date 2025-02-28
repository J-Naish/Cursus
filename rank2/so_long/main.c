/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:39:00 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 03:50:05 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	validate_arg(argc, argv);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (EXIT_FAILURE);
	validate_map(game.map);
	if (begin_play(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	tick(&game);
	end_play(&game);
	return (EXIT_SUCCESS);
}
