/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:51:18 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 08:14:54 by nash             ###   ########.fr       */
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
			map_error("Invalid character in map.");
		i++;
	}
}

static void	validate_composition(const char *map)
{
	if (!ft_strchr(map, '0') || !ft_strchr(map, '1')
		|| !ft_strchr(map, 'E') || !ft_strchr(map, 'P'))
		map_error("Map must contain '0', '1', 'E', and 'P'");
}

static void	validate_mapsize(const char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (len == 0)
		map_error("Map must not be empty.");
	if (len < 17)
		map_error("Map is too small.");
}

// size_t	count_new_line(char *s)
// {
// 	size_t	count;
// 	int		i;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// size_t	strarr_size(char **strarr)
// {
// 	size_t	count;

// 	while (strarr[count])
// 		count++;
// 	return (count);
// }

// size_t	linelen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	return (i);
// }

// void	validate_rect(const char *map)
// {
// 	char	**lines;
// 	size_t	size_lines;
// 	size_t	new_line_count;
// 	int		i;

// 	lines = ft_split(map, '\n');
// 	if (!lines)
// 	{
// 		ft_putstr_fd("Memory allocation failed.\n", STDERR_FILENO);
// 		exit(EXIT_FAILURE);
// 	}
// 	size_lines = strarr_size(lines);
// 	new_line_count = count_new_line(map);
// 	if (size_lines != new_line_count + 1)
// 	{
// 		ft_putstr_fd("Error\nToo many line feeds.\n", STDERR_FILENO);
// 		exit(EXIT_FAILURE);
// 	}
// 	i = 0;
// 	while (i < size_lines - 1)
// 	{
// 		if (linelen(lines[i]) != linelen(lines[i + 1]))
// 		{
// 			ft_putstr_fd("Error\nMap must be rect.\n", STDERR_FILENO);
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// }

void	validate_map(const char *map)
{
	validate_char(map);
	validate_mapsize(map);
	validate_composition(map);
	// col length validate (col >= 5, each col must be the same width)
	// row length validate (row >= 3)
	// wall validate
}

// int main() {
// 	char *test = "\n\n1111\n1111\n1111\n";
// 	char **lines = ft_split(test, '\n');
// 	printf("%s\n", lines[0]);
// 	printf("%s\n", lines[1]);
// 	printf("%s\n", lines[2]);
// 	printf("%s\n", lines[3]);
// }