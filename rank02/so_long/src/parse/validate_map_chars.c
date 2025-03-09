/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:51:18 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 10:22:56 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	validate_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			continue ;
		}
		if (!is_valid_char(map[i]))
			map_error("Invalid character in map.", map);
		i++;
	}
}

static void	validate_composition(char *map)
{
	if (!ft_strchr(map, WALL) || !ft_strchr(map, COLLECTIBLE)
		|| !ft_strchr(map, EXIT) || !ft_strchr(map, PLAYER))
		map_error("Map must contain '1', 'C', 'E', and 'P'", map);
}

static void	validate_p_e_count(char *map)
{
	int	p_count;
	int	e_count;
	int	i;

	p_count = 0;
	e_count = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p_count += 1;
		else if (map[i] == 'E')
			e_count += 1;
		i++;
	}
	if (p_count != 1)
		map_error("Map must not contain more than one P.", map);
	if (e_count != 1)
		map_error("Map must not contain more than one E.", map);
}

void	validate_chars(char *map)
{
	validate_char(map);
	validate_composition(map);
	validate_p_e_count(map);
}
