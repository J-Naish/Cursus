/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/24 04:58:12 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wait_children(int num_children)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_children)
	{
		if (wait(&status) == -1)
			error_exit();
		i++;
	}
	return (status);
}

static void	child_process(int i, t_arg *arg, int prev_pipefd, int pipefd[2])
{
	if (i == 2)
		dup_infile(arg->argv[1]);
	else
		safe_dup2(prev_pipefd, STDIN_FILENO);
	if (i == arg->argc - 2)
		dup_outfile(arg->argv[arg->argc - 1]);
	else
		safe_dup2(pipefd[1], STDOUT_FILENO);
	if (i < arg->argc - 2)
		close_pipefd(pipefd);
	exec_cmd(arg->argv[i], arg->envp);
}

static void	parent_process(int i, int argc, int *prev_pipefd, int pipefd[2])
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
			safe_pipe(pipefd);
		pid = safe_fork();
		if (pid == 0)
			child_process(i, &arg, prev_pipefd, pipefd);
		else
			parent_process(i, argc, &prev_pipefd, pipefd);
		i++;
	}
	return (wait_children(argc - 3));
}
