/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:33:41 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 02:38:01 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*read_wall(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/block.xpm", &width, &height));
}

void	*read_player(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/mario.xpm", &width, &height));
}

void	*read_collectible(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/coin.xpm", &width, &height));
}

void	*read_exit(void *mlx, int width, int height)
{
	return (mlx_xpm_file_to_image(mlx, "./assets/pipe.xpm", &width, &height));
}
