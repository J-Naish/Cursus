/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 06:31:30 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 07:27:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_wrapper(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		error_exit();
}

void	dup_infile(char *filepath)
{
	int	infilefd;

	infilefd = open(filepath, O_RDONLY);
	if (infilefd < 0)
		error_exit();
	dup2_wrapper(infilefd, STDIN_FILENO);
	close(infilefd);
}

void	dup_outfile(char *filepath)
{
	int	outfilefd;

	outfilefd = open(filepath, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfilefd < 0)
		error_exit();
	dup2_wrapper(outfilefd, STDOUT_FILENO);
	close(outfilefd);
}

void	close_pipefd(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

t_arg	init_arg(int argc, char **argv, char **envp)
{
	return ((t_arg){.argc = argc, .argv = argv, .envp = envp});
}
