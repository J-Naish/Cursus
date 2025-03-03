/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_playability.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:42:45 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 09:17:36 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **grid, t_transform size, int x, int y)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x
		|| grid[y][x] == WALL || grid[y][x] == VISITED)
		return ;
	grid[y][x] = VISITED;
	flood_fill(grid, size, x + 1, y);
	flood_fill(grid, size, x - 1, y);
	flood_fill(grid, size, x, y + 1);
	flood_fill(grid, size, x, y - 1);
}

static t_transform	find_player_pos(char **grid, t_transform size)
{
	int			i;
	int			j;
	t_transform	pos;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (grid[i][j] == PLAYER)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

static bool	includes(char **grid, t_transform size, int c)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		if (ft_strchr(grid[i], c))
			return (true);
		i++;
	}
	return (false);
}

void	validate_playability(char *map)
{
	char		**grid;
	t_transform	size;
	t_transform	pos_player;

	grid = ft_split(map, '\n');
	if (!grid)
	{
		free(map);
		map_error("Memory allocation failed.");
	}
	size.x = linelen(grid[0]);
	size.y = strarr_size(grid);
	pos_player = find_player_pos(grid, size);
	flood_fill(grid, size, pos_player.x, pos_player.y);
	if (includes(grid, size, EXIT) || includes(grid, size, COLLECTIBLE))
	{
		free_strarr(grid);
		free(map);
		map_error("Map is not playable.");
	}
	free_strarr(grid);
}
