/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 07:40:31 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 07:46:42 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	safe_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		error_exit();
}

void	safe_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		error_exit();
}

pid_t	safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit();
	return (pid);
}
