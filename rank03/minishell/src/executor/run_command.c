/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:13 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:13 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static void	run_builtin_command(t_command *command, char ***envpp)
{
	char	*cmd_name;

	cmd_name = get_cmd_name(command);
	if (is_same_str(cmd_name, "echo"))
		cmd_echo(command);
	else if (is_same_str(cmd_name, "cd"))
		cmd_cd(command, envpp);
	else if (is_same_str(cmd_name, "pwd"))
		cmd_pwd(command);
	else if (is_same_str(cmd_name, "export"))
		cmd_export(command, envpp);
	else if (is_same_str(cmd_name, "unset"))
		cmd_unset(command, envpp);
	else if (is_same_str(cmd_name, "env"))
		cmd_env(command, envpp);
	else if (is_same_str(cmd_name, "exit"))
		cmd_exit(command);
}

static t_str_heap	join_path(t_str dir, t_str cmd)
{
	t_str_heap	temp;
	t_str_heap	full_path;

	temp = ft_strjoin(dir, "/");
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

static t_str_heap	find_command_path(t_command *command, char ***envpp)
{
	t_str_heap		full_path;
	t_str_arr_heap	paths;
	t_str			cmd;
	int				i;
	t_str			env_path;

	cmd = get_cmd_name(command);
	if (ft_strchr(cmd, '/') || ft_strchr(cmd, '.'))
		return (ft_strdup(cmd));
	env_path = get_env_value("PATH", *envpp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (access(full_path, F_OK) == 0)
			return (free_str_arr(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_str_arr(paths), NULL);
}

static void	run_external_command(t_command *command, char ***envpp)
{
	t_str_heap	cmd_path;

	cmd_path = find_command_path(command, envpp);
	if (!cmd_path)
		command_not_found(get_cmd_name(command));
	execve(cmd_path, command->args, *envpp);
	put_error(SHELL_NAME": ");
	put_error(cmd_path);
	put_error(": ");
	put_error(strerror(errno));
	put_error("\n");
	if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) != 0)
		exit(EXIT_UNABLE_TO_EXECUTE);
	else
		exit(EXIT_NOT_FOUND);
}

void	run_command(t_command *command, char ***envpp)
{
	int		saved_fds[2];

	if (command->is_redirect)
	{
		save_std_fds(saved_fds);
		if (!setup_input_redirect(command) || !setup_output_redirect(command))
		{
			restore_std_fds(saved_fds);
			return ;
		}
	}
	if (is_builtin_cmd(command))
		run_builtin_command(command, envpp);
	else
		run_external_command(command, envpp);
	if (command->is_redirect)
		restore_std_fds(saved_fds);
}
