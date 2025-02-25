/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:50:42 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 23:13:13 by nash             ###   ########.fr       */
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
void	command_not_found(void);
void	malloc_failure_exit(void);
void	arg_error(void);

void	exec_cmd(char *cmd, char **envp);

void	safe_dup2(int fd1, int fd2);
void	safe_pipe(int pipefd[2]);
pid_t	safe_fork(void);

void	dup_infile(char *filepath);
void	dup_outfile(char *filepath);
char	**split_cmd(char const *cmd);

#endif