/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:56:49 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 22:53:09 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		malloc_failure_exit();
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full_path)
		malloc_failure_exit();
	return (full_path);
}

static char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				malloc_failure_exit();
			return (paths);
		}
		i++;
	}
	return (NULL);
}

static void	free_strarr(char **paths)
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

	if (ft_strchr(cmd, '/'))
	{
		full_path = ft_strdup(cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
			return (free(full_path), NULL);
	}
	paths = get_paths(envp);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (free_strarr(paths), full_path);
		free(full_path);
		i++;
	}
	free_strarr(paths);
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = split_cmd(cmd);
	cmd_path = find_command_path(args[0], envp);
	if (!cmd_path)
	{
		free_strarr(args);
		free(cmd_path);
		ft_putstr_fd("command not found\n", STDERR_FILENO);
		exit(127);
	}
	execve(cmd_path, args, envp);
	free_strarr(args);
	free(cmd_path);
	error_exit();
}
