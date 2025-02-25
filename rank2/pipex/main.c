/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 01:51:03 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run_cmd_process(char *arg, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	safe_pipe(pipefd);
	pid = safe_fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		safe_dup2(pipefd[1], STDOUT_FILENO);
		exec_cmd(arg, envp);
	}
	else
	{
		close(pipefd[1]);
		safe_dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

static void	here_doc(char *limiter)
{
	int		pipefd[2];
	char	*line;

	safe_pipe(pipefd);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	close(pipefd[1]);
	safe_dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}

static void	append_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		error_exit();
	safe_dup2(fd, STDOUT_FILENO);
	close(fd);
}

static void	run_last_cmd(int argc, char **argv, char **envp, bool is_heredoc)
{
	if (is_heredoc)
		append_outfile(argv[argc - 1]);
	else
		dup_outfile(argv[argc - 1]);
	exec_cmd(argv[argc - 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	bool	is_heredoc;

	is_heredoc = (argc > 1 && ft_strncmp(argv[1], "here_doc", 8) == 0);
	if ((!is_heredoc && argc < 5) || (is_heredoc && argc < 6))
		arg_error();
	if (is_heredoc)
	{
		here_doc(argv[2]);
		i = 3;
	}
	else
	{
		dup_infile(argv[1]);
		i = 2;
	}
	while (i < argc - 2)
	{
		run_cmd_process(argv[i], envp);
		i++;
	}
	run_last_cmd(argc, argv, envp, is_heredoc);
	return (EXIT_SUCCESS);
}
