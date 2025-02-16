/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 04:06:40 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_all(int argc, char **argv, char **envp)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;

	i = 2;
	(void) envp;
	while (i < argc - 1)
	{
		if (pipe(pipefd) == -1)
			error_exit();
		pid = fork();
		if (pid == -1)
			error_exit();
		if (pid == 0)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		i++;
	}
	i = 2;
	while (i < argc - 1)
	{
		wait(NULL);
		i++;
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
	process_all(argc, argv, envp);
	return (0);
}
