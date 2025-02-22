/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 07:36:23 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wait_children(int num_children)
{
	int	i;
	int	status;
	int	result;

	i = 0;
	result = EXIT_SUCCESS;
	while (i < num_children)
	{
		if (waitpid(-1, &status, 0) == -1)
			error_exit();
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
			result = EXIT_FAILURE;
		i++;
	}
	return (result);
}

static void	pipe_wrapper(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		error_exit();
}

static pid_t	fork_wrapper(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit();
	return (pid);
}

void	child_process(int i, t_arg *arg, int prev_pipefd, int pipefd[2])
{
	if (i == 2)
		dup_infile(arg->argv[1]);
	else
		dup2_wrapper(prev_pipefd, STDIN_FILENO);
	if (i == arg->argc - 2)
		dup_outfile(arg->argv[arg->argc - 1]);
	else
		dup2_wrapper(pipefd[1], STDOUT_FILENO);
	if (i < arg->argc - 2)
		close_pipefd(pipefd);
	exec_cmd(arg->argv[i], arg->envp);
}

void	parent_process(int i, int argc, int *prev_pipefd, int pipefd[2])
{
	if (*prev_pipefd != -1)
		close(*prev_pipefd);
	if (i < argc - 2)
	{
		*prev_pipefd = pipefd[0];
		close(pipefd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;
	int		prev_pipefd;
	t_arg	arg;

	if (argc < 5)
		return (0);
	arg = init_arg(argc, argv, envp);
	prev_pipefd = -1;
	i = 2;
	while (i < argc - 1)
	{
		if (i < argc - 2)
			pipe_wrapper(pipefd);
		pid = fork_wrapper();
		if (pid == 0)
			child_process(i, &arg, prev_pipefd, pipefd);
		else
			parent_process(i, argc, &prev_pipefd, pipefd);
		i++;
	}
	return (wait_children(argc - 3));
}
