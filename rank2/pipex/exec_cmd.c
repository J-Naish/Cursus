/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:56:49 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 01:38:38 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full_path)
		return (NULL);
	return (full_path);
}

static char	**get_paths(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

static void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static char	*find_command_path(const char *cmd, char **envp)
{
	char	*full_path;
	char	**paths;
	int		i;

	paths = get_paths(envp);
	if (!paths)
		error_exit();
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (!full_path)
			error_exit();
		if (access(full_path, X_OK) == 0)
			return (free_paths(paths), full_path);
		free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = get_cmd_args(cmd);
	if (!args)
		error_exit();
	if (ft_strchr(cmd, '/'))
		cmd_path = ft_strdup(cmd);
	else
		cmd_path = find_command_path(args[0], envp);
	if (execve(cmd_path, args, envp) == -1)
		error_exit();
}
