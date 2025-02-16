/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 03:50:16 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	pipex()
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		error_exit();
	pid = fork();
	if (pid == -1)
		error_exit();
	if (pid == 0)
	{
		close(pipefd[1]);
		close(pipefd[0]);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pipefd[0]);
		close(pipefd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infilefd;
	int	outfilefd;

	if (argc < 5)
		return (0);
	infilefd = open(argv[1], O_RDONLY);
	if (infilefd < 0)
		error_exit();
	outfilefd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfilefd < 0)
		error_exit();
	(void) envp;
	pipex();
	return (0);
}
