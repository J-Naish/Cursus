/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 04:01:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_children(int num_children)
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

void	dup2_wrapper(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		error_exit();
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
				infilefd = open_infile(argv[1]);
				dup2_wrapper(infilefd, STDIN_FILENO);
				close(infilefd);
			}
			else
				dup2_wrapper(prev_pipe_fd, STDIN_FILENO);
			if (i == argc - 2)
			{
				dup2_wrapper(prev_pipe_fd, STDIN_FILENO);
				outfilefd = open_outfile(argv[argc - 1]);
				dup2_wrapper(outfilefd, STDOUT_FILENO);
				close(outfilefd);
			}
			else
				dup2_wrapper(pipefd[1], STDOUT_FILENO);
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
	return (wait_children(argc - 3));
}
