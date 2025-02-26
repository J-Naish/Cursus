/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 04:11:48 by nash              #+#    #+#             */
/*   Updated: 2025/02/27 04:50:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	count_new_line(const char *s)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

size_t	strarr_size(char **strarr)
{
	size_t	count;

	count = 0;
	while (strarr[count])
		count++;
	return (count);
}

size_t	linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	free_strarr(char **lines)
{
	int	lines_count;
	int	i;

	lines_count = strarr_size(lines);
	i = 0;
	while (i < lines_count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (true);
	else
		return (false);
}
