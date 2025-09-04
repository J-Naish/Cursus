#ifndef TYPES_H
# define TYPES_H

# include <stdint.h>

# ifndef EMPTY
#  define EMPTY '0'
# endif
# ifndef WALL
#  define WALL '1'
# endif
# ifndef PLAYER_N
#  define PLAYER_N 'N'
# endif
# ifndef PLAYER_S
#  define PLAYER_S 'S'
# endif
# ifndef PLAYER_E
#  define PLAYER_E 'E'
# endif
# ifndef PLAYER_W
#  define PLAYER_W 'W'
# endif
# ifndef VOID
#  define VOID ' '
# endif

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	plane;
	float		move_speed;
	float		rot_speed;
}	t_player;

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	int			tex_y;
}	t_ray;

typedef struct s_level
{
	char	**map;
	char	*n_texture_path;
	char	*s_texture_path;
	char	*w_texture_path;
	char	*e_texture_path;
	t_color	floor;
	t_color	ceiling;
}	t_level;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_level		*level;
	t_player	player;
	t_texture	textures[4];
	t_image		img;
}	t_game;

#endif
