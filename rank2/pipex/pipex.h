/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:50:42 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 01:37:07 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	free_all(char *infilename, char *outfilename, char **cmds);

char	**get_cmds(int argc, char **argv);
char	*get_infilename(char **argv);
char	*get_outfilename(int argc, char **argv);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_putstr_fd(int fd, const char *s);

#endif