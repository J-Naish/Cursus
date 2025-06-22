/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:02:30 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 19:02:30 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

bool	is_same_key(char *new_env, char *env)
{
	int	equal_pos;
	int	i;

	equal_pos = 0;
	while (env[equal_pos])
	{
		if (env[equal_pos] == '=')
			break ;
		equal_pos++;
	}
	i = 0;
	while (i < equal_pos)
	{
		if (new_env[i] != env[i])
			return (false);
		i++;
	}
	return (true);
}

bool	env_key_exists(char *new_env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (is_same_key(new_env, envp[i]))
			return (true);
		i++;
	}
	return (false);
}

char	*get_env_value(char *key, char **envpp)
{
	int	i;
	int	key_len;

	if (!key || !envpp)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envpp[i])
	{
		if (ft_strncmp(envpp[i], key, key_len) == 0 && envpp[i][key_len] == '=')
			return (&envpp[i][key_len + 1]);
		i++;
	}
	return (NULL);
}
