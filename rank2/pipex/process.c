/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:06:53 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 03:30:35 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile()
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
