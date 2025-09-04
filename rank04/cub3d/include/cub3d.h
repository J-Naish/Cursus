#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

# include "types.h"
# include "macros.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/minilibx/mlx.h"

// debug
void			debug_level(t_level *level);
void			debug_map(char **map);

// game
t_game			*init_game(t_level *level);
void			destroy_game(t_game *game);
void			init_player(t_player *player, t_level *level);
bool			load_textures(t_game *game);
void			destroy_textures(t_game *game);
void			start_game(t_game *game);
int				game_loop(t_game *game);
int				close_window(t_game *game);

// render
void			cast_ray(t_ray *ray, t_player *player, char **map, int x);
void			draw_vertical_line(t_game *game, int x, t_ray *ray);
void			draw_floor_and_ceiling(t_game *game, int x);
void			render_frame(t_game *game);

// input
int				key_press(int keycode, t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);

// input/parse
t_color			get_color(char *color_string);
char			**get_map(char **map_lines);
t_level			*get_level(char *content);

// input/validation
bool			ends_with_map(char **lines);
bool			includes_no_extraneous_line(char **lines);
bool			includes_valid_colors(char **lines);
bool			includes_valid_map(char **lines);
bool			includes_valid_texture_paths(char **lines);
bool			is_config_line(char *line);
bool			is_map_line(char *s);
bool			is_valid_map(char **map_lines);
void			validate_arg(int argc, char **argv);
void			validate_cub(char *content);

// input
char			**extract_map_lines(char **lines);
char			**get_lines(char *content);
int				get_identifier_index(char **lines, char *identifier);
bool			includes_unique_identifier(char **lines, char *identifier);
char			*read_file(int fd);

// utils
// error
void			put_error(char *msg);
void			exit_with_error_msg(char *msg);
// level
void			free_level(t_level *level);
// map
bool			is_player(char symbol);
bool			is_empty(char c);
bool			is_wall(char c);
bool			is_void(char c);
bool			is_map_symbol(char c);
// string_array
void			free_strarr(char **strarr);
char			**calloc_strarr(size_t size);
size_t			strarr_length(char **strarr);
// string
bool			includes(char *s, char *substr);
bool			starts_with(char *s, char *prefix);
bool			ends_with(char *str, char *ending);
bool			equals(char *s1, char *s2);

#endif
