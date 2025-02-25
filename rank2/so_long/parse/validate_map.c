/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:51:18 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 07:30:51 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (true);
	else
		return (false);
}

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
		{
			ft_putstr_fd("Error\nInvalid character in map. ", STDERR_FILENO);
			ft_putstr_fd("Only '0', '1', 'C', 'E', and 'P' ", STDERR_FILENO);
			ft_putstr_fd("are allowed.\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	validate_composition(const char *map)
{
	if (!ft_strchr(map, '0') || !ft_strchr(map, '1')
		|| !ft_strchr(map, 'E') || !ft_strchr(map, 'P'))
	{
		ft_putstr_fd("Error\nMap must contain ", STDERR_FILENO);
		ft_putstr_fd("'0', '1', 'E', and 'P'\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static void	validate_mapsize(const char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (len == 0)
	{
		ft_putstr_fd("Error\nMap is empty.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (len < 17)
	{
		ft_putstr_fd("Error\nMap is too small.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	validate_map(const char *map)
{
	validate_char(map);
	validate_mapsize(map);
	validate_composition(map);
	// row length validate
	// col length validate
	// wall validate
}

// int main() {
// 	char *map = "11111111\n10000001\n10000001";
// 	// linelen test
// 	printf("%zu\n", linelen(map));
// }