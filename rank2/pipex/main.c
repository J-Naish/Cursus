/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 18:59:20 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_children(int num_children)
{
	int	i;

	i = 0;
	while  (i < num_children)
	{
		wait(NULL);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		infilefd;
	int		outfilefd;
	int		i;
	int		pipefd[2];
	pid_t	pid;
	int		prev_pipe_fd;

	prev_pipe_fd = -1;
	if (argc < 5)
		return (0);
	infilefd = open(argv[1], O_RDONLY);
	if (infilefd < 0)
		error_exit();
	outfilefd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfilefd < 0)
		error_exit();
	i = 2;
	while (i < argc - 1)
	{
		if (i < argc - 2)
		{
			if (pipe(pipefd) == -1)
				error_exit();
		}
		pid = fork();
		if (pid == -1)
			error_exit();
		else if (pid == 0)
		{
			if (i == 2)
			{
				if (dup2(infilefd, STDIN_FILENO) == -1)
					error_exit();
				close(infilefd);
			}
			else
			{
				if (dup2(prev_pipe_fd, STDIN_FILENO) == -1)
					error_exit();
			}
			if (i == argc - 2)
			{
				if (dup2(prev_pipe_fd, STDIN_FILENO) == -1)
					error_exit();
				if (dup2(outfilefd, STDOUT_FILENO) == -1)
					error_exit();
				close(outfilefd);
			}
			else
			{
				if (dup2(pipefd[1], STDOUT_FILENO) == -1)
					error_exit();
			}
			if (i < argc - 2)
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			exec_cmd(argv[i], envp);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (prev_pipe_fd != -1)
				close(prev_pipe_fd);
			if (i < argc - 2)
			{
				prev_pipe_fd = pipefd[0];
				close(pipefd[1]);
			}
		}
		i++;
	}
	wait_children(argc - 3);
	return (0);
}
