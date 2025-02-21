/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:56:49 by nash              #+#    #+#             */
/*   Updated: 2025/02/21 19:39:37 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(const char *dir, const char *cmd)
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

char	*get_path_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_command_path(const char *cmd, char **envp)
{
	char	*path_env;
	char	*paths;
	char	*token;
	char	*saveptr;
	char	*full_path;

	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_strdup(path_env);
	if (!paths)
		return (NULL);
	token = strtok_r(paths, ":", &saveptr);
	while (token != NULL)
	{
		full_path = join_path(token, cmd);
		if (!full_path)
			return (free(paths), NULL);
		if (access(full_path, X_OK) == 0)
			return (free(paths), full_path);
		free(full_path);
		token = strtok_r(NULL, ":", &saveptr);
	}
	free(paths);
	return (NULL);
}

// void	exec_cmd(char *cmd, char **envp)
// {
// 	char	**args;
// 	char	*cmd_path = NULL;

// 	if (ft_strchr(cmd, '/') == NULL)
// 	{
// 		args = get_cmd_args(cmd);
// 		if (!args)
// 			error_exit();
// 		cmd_path = find_command_path(args[0], envp);
// 		if (!cmd_path)
// 		{
// 			error_exit();
// 		}
// 	}
// 	else
// 	{
// 		cmd_path = strdup(cmd);
// 		if (!cmd_path)
// 			error_exit();
// 		args = get_cmd_args(cmd);
// 		if (!args)
// 		{
// 			free(cmd_path);
// 			error_exit();
// 		}
// 	}

// 	if (execve(cmd_path, args, envp) == -1)
// 	{
// 		free(cmd_path);
// 		error_exit();
// 	}
// }


// int main() {
// 	printf("%s\n", join_path("bin", "ls"));
// }