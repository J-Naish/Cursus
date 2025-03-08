/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/03/08 22:01:39 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	run_cmd_process(char *arg, char **envp)
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
	}
	return (pid);
}

static pid_t	run_last_cmd(int argc, char **argv, char **envp,
		bool is_heredoc)
{
	pid_t	pid;

	pid = safe_fork();
	if (pid == 0)
	{
		if (is_heredoc)
			append_outfile(argv[argc - 1]);
		else
			dup_outfile(argv[argc - 1]);
		exec_cmd(argv[argc - 2], envp);
	}
	return (pid);
}

static int	wait_child(int status, pid_t last_pid)
{
	while (waitpid(-1, &status, 0) != last_pid)
		;
	while (waitpid(-1, NULL, 0) > 0)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	pid_t	last_pid;
	int		status;

	if ((!is_here_doc(argc, argv) && argc < 5)
		|| (is_here_doc(argc, argv) && argc < 6))
		arg_error();
	if (is_here_doc(argc, argv))
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
	last_pid = run_last_cmd(argc, argv, envp, is_here_doc(argc, argv));
	status = 0;
	return (wait_child(status, last_pid));
}
