/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:39:12 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 02:38:46 by nash             ###   ########.fr       */
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
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

void	map_error(char *message);

char	*get_next_line(int fd);
char	*read_map(const char *filename);

void	validate_arg(int argc, char **argv);

size_t	count_new_line(const char *s);
size_t	strarr_size(char **strarr);
size_t	linelen(const char *s);
void	free_strarr(char **lines);
bool	is_valid_char(char c);

void	validate_chars(const char *map);
void	validate_rect(const char *map);

void	validate_map(const char *map);

void	*read_wall(void *mlx, int width, int height);
void	*read_player(void *mlx, int width, int height);
void	*read_collectible(void *mlx, int width, int height);
void	*read_exit(void *mlx, int width, int height);

#endif