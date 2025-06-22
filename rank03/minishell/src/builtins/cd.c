/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:02 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:02 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static t_str	get_home_dir(char ***envpp)
{
	t_str	env_home;

	env_home = get_env_value("HOME", *envpp);
	if (!env_home)
	{
		put_error(SHELL_NAME": path is unset\n");
		return (NULL);
	}
	return (env_home);
}

static t_str_heap	expand_tilde_path(char *path, char ***envpp)
{
	t_str	env_home;

	env_home = get_home_dir(envpp);
	if (!env_home)
		return (NULL);
	if (ft_strlen(path) > 1)
		return (ft_strjoin(env_home, &path[1]));
	else
		return (ft_strdup(env_home));
}

static t_str_heap	get_target_directory(t_command *command, char ***envpp)
{
	t_str	env_home;

	if (command->args[1] && starts_with(command->args[1], "~"))
		return (expand_tilde_path(command->args[1], envpp));
	else if (!command->args[1])
	{
		env_home = get_home_dir(envpp);
		if (!env_home)
			return (NULL);
		return (ft_strdup(env_home));
	}
	else
		return (ft_strdup(command->args[1]));
}

void	cmd_cd(t_command *command, char ***envpp)
{
	t_str_heap	target_dir;

	target_dir = get_target_directory(command, envpp);
	if (!target_dir)
		return ;
	if (chdir(target_dir) == -1)
		perror(SHELL_NAME": cd");
	free(target_dir);
}
