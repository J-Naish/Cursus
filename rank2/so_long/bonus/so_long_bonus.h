/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:39:12 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 07:32:10 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

# ifndef ANIMATION_SPEED
#  define ANIMATION_SPEED 1
# endif

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 3
# endif

# ifndef EMPTY
#  define EMPTY '0'
# endif

# ifndef WALL
#  define WALL '1'
# endif

# ifndef PLAYER
#  define PLAYER 'P'
# endif

# ifndef EXIT
#  define EXIT 'E'
# endif

# ifndef COLLECTIBLE
#  define COLLECTIBLE 'C'
# endif

# ifndef ENEMY
#  define ENEMY 'e'
# endif

typedef struct t_transform
{
	int	x;
	int	y;
}	t_transform;

typedef struct t_player
{
	t_transform	pos;
	int			moves;
	int			collected_collectibles;
}	t_player;

typedef struct t_enemy
{
	t_transform	pos;
	int			move_count;
}	t_enemy;

typedef struct t_animation
{
	void	*frames[ANIMATION_FRAMES];
}	t_animation;

typedef struct t_sprite
{
	void	*empty;
	void	*wall;
	void	*player;
	void	**collectible;
	void	*exit;
	void	*enemy;
}	t_sprite;

typedef struct t_game
{
	void		*mlx;
	void		*window;
	t_sprite	images;
	char		*map;
	int			width;
	int			height;
	int			tile_size;
	t_player	player;
	t_enemy		enemy;
	int			enemy_move_counter;
	int			num_collectibles;
	int			current_frame;
	int			frame_counter;
	int			animation_speed;
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

void	load_images(t_game *game);
void	render_map(t_game *game);

void	spawn_enemy(t_game *game);
void	move_enemy(t_game *game);

void	spawn_player(t_game *game);
void	move_player(t_game *game, int dx, int dy);

void	beat_game(t_game *game);
void	game_over(t_game *game);
void	destroy_game(t_game *game);

void	begin_play(t_game *game);
void	tick(t_game *game);
void	end_play(t_game *game);

#endif