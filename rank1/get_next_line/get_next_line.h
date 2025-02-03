/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:51 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 16:56:40 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_join_and_free(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
bool	ft_includes_newline(char *s);
size_t	ft_strlen(const char *s);

#endif