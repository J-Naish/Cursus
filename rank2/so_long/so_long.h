/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:39:12 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 04:20:20 by nash             ###   ########.fr       */
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

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

typedef struct t_game
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*empty;
	char	*map;
	int		width;
	int		height;
	int		tile_size;
}	t_game;

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

void	begin_play(t_game *game);
void	tick(t_game *game);
void	end_play(t_game *game);

#endif