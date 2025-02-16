/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:06:53 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 02:38:12 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(char *infilename)
{
	int		fd;
	int		pipefd[2];
	pid_t	pid;

	fd = open(infilename, O_RDONLY);
	if (fd < 0)
	{
		puterrno();
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
	{
		puterrno();
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		puterrno();
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		printf("child process\n");
		close(pipefd[1]);
		close(pipefd[0]);
	}
	else
	{
		printf("parent process\n");
		close(pipefd[0]);
		close(pipefd[1]);
		wait(NULL);
	}
}
