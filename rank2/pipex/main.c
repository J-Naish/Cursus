/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 21:51:20 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process(char *arg, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	safe_pipe(pipefd);
	pid = safe_fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		safe_dup2(pipefd[1], STDOUT_FILENO);
		exec_cmd(arg, envp);
	}
	else
	{
		close(pipefd[1]);
		safe_dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	if (argc < 5)
		arg_error();
	dup_infile(argv[1]);
	i = 2;
	while (i < argc - 2)
		process(argv[i++], envp);
	dup_outfile(argv[argc - 1]);
	exec_cmd(argv[argc - 2], envp);
}
