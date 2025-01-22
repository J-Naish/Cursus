/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:30:51 by nash              #+#    #+#             */
/*   Updated: 2025/01/22 22:52:29 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

// char	*get_next_char__malloc(int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
bool	ft_includes_newline(char *s);