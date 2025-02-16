/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:06:53 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 02:54:17 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(char *infilename, char *outfilename, char **cmds)
{
	int		fd;
	int		pipefd[2];
	pid_t	pid;

	fd = open(infilename, O_RDONLY);
	if (fd < 0)
		error_exit(infilename, outfilename, cmds);
	if (pipe(pipefd) == -1)
		error_exit(infilename, outfilename, cmds);
	pid = fork();
	if (pid == -1)
		error_exit(infilename, outfilename, cmds);
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
