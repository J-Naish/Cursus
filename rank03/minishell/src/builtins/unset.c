/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:22 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static void	remove_env(char *env_key, char ***envpp)
{
	int				size;
	int				i;
	int				j;
	t_str_arr_heap	new;

	size = 0;
	while ((*envpp)[size])
		size++;
	new = (t_str_arr_heap)malloc(sizeof(t_str *) * size);
	i = 0;
	j = 0;
	while ((*envpp)[i])
	{
		if (!is_same_key(env_key, (*envpp)[i]))
		{
			new[j] = ft_strdup((*envpp)[i]);
			j++;
		}
		i++;
	}
	new[j] = NULL;
	free_str_arr(*envpp);
	*envpp = new;
}

void	unset_env(char *env, char ***envpp)
{
	if (!env_key_exists(env, *envpp))
		return ;
	remove_env(env, envpp);
}

void	cmd_unset(t_command *command, char ***envpp)
{
	int	i;

	if (!command->args[1])
		return ;
	i = 1;
	while (command->args[i])
	{
		unset_env(command->args[i], envpp);
		i++;
	}
}
