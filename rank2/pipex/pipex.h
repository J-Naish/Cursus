/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:50:42 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 04:08:14 by nash             ###   ########.fr       */
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

void	puterrno(void);
void	error_exit(void);

void	exec_cmd(char *cmd, char **envp);

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(int fd, const char *s);

#endif