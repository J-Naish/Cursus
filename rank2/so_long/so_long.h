/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:39:12 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 08:09:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef enum e_map
{
	EMPTY,
	WALL,
	COLLECTIBLE,
	EXIT,
	START_POSITION,
	INVALID
}	t_map;

void	map_error(char *message);

char	*get_next_line(int fd);
char	*read_map(const char *filename);
void	validate_arg(int argc, char **argv);
void	validate_map(const char *map);

#endif