/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:51:18 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 07:01:42 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static size_t	get_linelen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	return (i);
// }

static bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (true);
	else
		return (false);
}

void	is_composed_of_valid_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			continue ;
		if (!is_valid_char(map[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
		}
		i++;
	}
}

bool	validate_map(const char *map)
{
	is_composed_of_valid_char(map);
}

// int main() {
// 	char *map = "11111111\n10000001\n10000001";
// 	// linelen test
// 	printf("%zu\n", linelen(map));
// }