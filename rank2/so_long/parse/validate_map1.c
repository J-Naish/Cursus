/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:51:18 by nash              #+#    #+#             */
/*   Updated: 2025/02/27 04:53:25 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	validate_char(const char *map)
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
			map_error("Invalid character in map.");
		i++;
	}
}

static void	validate_composition(const char *map)
{
	if (!ft_strchr(map, '1')
		|| !ft_strchr(map, 'E') || !ft_strchr(map, 'P'))
		map_error("Map must contain '0', '1', 'E', and 'P'");
}

void	validate_chars(const char *map)
{
	validate_char(map);
	validate_composition(map);
}
