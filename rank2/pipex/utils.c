/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 06:31:30 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 08:12:44 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_infile(char *filepath)
{
	int	infilefd;

	infilefd = open(filepath, O_RDONLY);
	if (infilefd < 0)
		error_exit();
	safe_dup2(infilefd, STDIN_FILENO);
	close(infilefd);
}

void	dup_outfile(char *filepath)
{
	int	outfilefd;

	outfilefd = open(filepath, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfilefd < 0)
		error_exit();
	safe_dup2(outfilefd, STDOUT_FILENO);
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

char	**get_cmd_args(char const *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error_exit();
	return (cmd_args);
}
