/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:00 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 19:00:38 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static bool	is_delimiter(t_str_heap line, t_str_heap delimiter)
{
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
		&& line[ft_strlen(delimiter)] == '\n')
		return (true);
	else
		return (false);
}

static t_str_heap	read_heredoc_line(void)
{
	t_str_heap	line;

	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	if (!line)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (line);
}

static void	process_heredoc_input(t_command *command, int write_fd)
{
	t_str_heap	line;

	while (1)
	{
		line = read_heredoc_line();
		if (!line)
			break ;
		if (is_delimiter(line, command->delimiter))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, write_fd);
		free(line);
	}
}

void	heredoc(t_command *command)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
	{
		perror(SHELL_NAME": ");
		return ;
	}
	process_heredoc_input(command, pipe_fds[1]);
	close(pipe_fds[1]);
	command->heredoc_pipe = pipe_fds[0];
}
