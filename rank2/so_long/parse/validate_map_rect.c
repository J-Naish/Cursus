/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_rect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 04:38:46 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 09:29:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	validate_new_line(char **lines, char *map)
{
	if (strarr_size(lines) != count_new_line(map) + 1)
		map_error("Too many line feeds.", map);
}

static void	validate_linelen(char **lines, char *map)
{
	int	i;
	int	line_count;

	i = 0;
	line_count = strarr_size(lines);
	while (i < line_count - 1)
	{
		if (linelen(lines[i]) != linelen(lines[i + 1]))
			map_error("Map must be rect.", map);
		i++;
	}
}

static void	validate_walls(char **lines, char *map)
{
	int	i;
	int	j;
	int	last_row;

	i = 0;
	last_row = strarr_size(lines) - 1;
	while (i <= last_row)
	{
		if (i == 0 || i == last_row)
		{
			j = 0;
			while (lines[i][j])
			{
				if (lines[i][j++] != WALL)
					map_error("The outline must be wall.", map);
			}
		}
		if (lines[i][0] != WALL || lines[i][linelen(lines[i]) - 1] != WALL)
			map_error("The outline must be wall.", map);
		i++;
	}
}

static void	validate_map_size(char **lines, char *map)
{
	if (strarr_size(lines) < 3)
		map_error("Map Y must not be fewer than 3.", map);
	if (ft_strlen(lines[0]) < 5)
		map_error("Map X must not be fewer than 5.", map);
}

void	validate_rect(char *map)
{
	char	**lines;

	lines = ft_split(map, '\n');
	if (!lines)
	{
		ft_putstr_fd("Memory allocation failed.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	validate_new_line(lines, map);
	validate_linelen(lines, map);
	validate_walls(lines, map);
	validate_map_size(lines, map);
	free_strarr(lines);
}
