/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:11 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

void	save_std_fds(int saved_fds[2])
{
	saved_fds[0] = dup(STDIN_FILENO);
	saved_fds[1] = dup(STDOUT_FILENO);
}

void	restore_std_fds(int saved_fds[2])
{
	dup2(saved_fds[0], STDIN_FILENO);
	dup2(saved_fds[1], STDOUT_FILENO);
	close(saved_fds[0]);
	close(saved_fds[1]);
}

bool	setup_input_redirect(t_command *command)
{
	int	fd;

	if (command->input_file)
	{
		fd = open(command->input_file, O_RDONLY);
		if (fd == -1)
			return (perror(SHELL_NAME": "), false);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (command->heredoc_pipe != -1)
	{
		dup2(command->heredoc_pipe, STDIN_FILENO);
		close(command->heredoc_pipe);
		command->heredoc_pipe = -1;
	}
	return (true);
}

bool	setup_output_redirect(t_command *command)
{
	int	fd;
	int	flags;

	if (command->output_file)
	{
		flags = O_WRONLY | O_CREAT;
		if (command->append_output)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		fd = open(command->output_file, flags, 0644);
		if (fd == -1)
			return (perror(SHELL_NAME": "), false);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (true);
}
