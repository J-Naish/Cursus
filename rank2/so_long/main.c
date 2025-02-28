/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:39:00 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 00:41:58 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;
	void	*mlx_ptr;
	void	*win_ptr;

	validate_arg(argc, argv);
	map = read_map(argv[1]);
	validate_map(map);
	printf("%s\n", map);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (free(map), EXIT_FAILURE);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
	if (!win_ptr)
		return (free(map), free(mlx_ptr), EXIT_FAILURE);
	free(map);
	free(mlx_ptr);
	free(win_ptr);
	return (EXIT_SUCCESS);
}
