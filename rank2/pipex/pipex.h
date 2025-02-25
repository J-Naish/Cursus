/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:50:42 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 20:43:45 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "./libft/libft.h"

typedef struct t_arg
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_arg;

void	error_exit(void);
void	malloc_failure_exit(void);

void	exec_cmd(char *cmd, char **envp);

void	safe_dup2(int fd1, int fd2);
void	safe_pipe(int pipefd[2]);
pid_t	safe_fork(void);

void	dup_infile(char *filepath);
void	dup_outfile(char *filepath);
void	close_pipefd(int pipefd[2]);
t_arg	init_arg(int argc, char **argv, char **envp);
char	**get_cmd_args(char const *cmd);

#endif