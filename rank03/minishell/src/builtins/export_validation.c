/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:02:00 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 19:02:00 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static t_str_heap	extract_key(char *new_env)
{
	int			equal_pos;
	int			i;
	t_str_heap	key;

	equal_pos = 0;
	while (new_env[equal_pos])
	{
		if (new_env[equal_pos] == '=')
			break ;
		equal_pos++;
	}
	key = (t_str_heap)malloc(sizeof(char) * (equal_pos + equal_pos + 1));
	i = 0;
	while (i < equal_pos)
	{
		key[i] = new_env[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

static bool	is_valid_char(char c)
{
	if (ft_isalnum(c))
		return (true);
	else if (c == '_')
		return (true);
	else
		return (false);
}

bool	is_valid_format(char *new_env)
{
	t_str_heap	key;
	int			i;

	key = extract_key(new_env);
	if (!ft_isalpha(key[0]))
		return (free(key), false);
	i = 0;
	while (key[i])
	{
		if (!is_valid_char(key[i]))
			return (free(key), false);
		i++;
	}
	return (free(key), true);
}
