#include "../../include/cub3d.h"
#include <math.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x + game->player.direction.x
		* game->player.move_speed;
	new_y = game->player.position.y + game->player.direction.y
		* game->player.move_speed;
	if (game->level->map[(int)game->player.position.y][(int)new_x] != WALL)
		game->player.position.x = new_x;
	if (game->level->map[(int)new_y][(int)game->player.position.x] != WALL)
		game->player.position.y = new_y;
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x - game->player.direction.x
		* game->player.move_speed;
	new_y = game->player.position.y - game->player.direction.y
		* game->player.move_speed;
	if (game->level->map[(int)game->player.position.y][(int)new_x] != WALL)
		game->player.position.x = new_x;
	if (game->level->map[(int)new_y][(int)game->player.position.x] != WALL)
		game->player.position.y = new_y;
}

static void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x - game->player.plane.x
		* game->player.move_speed;
	new_y = game->player.position.y - game->player.plane.y
		* game->player.move_speed;
	if (game->level->map[(int)game->player.position.y][(int)new_x] != WALL)
		game->player.position.x = new_x;
	if (game->level->map[(int)new_y][(int)game->player.position.x] != WALL)
		game->player.position.y = new_y;
}

static void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.position.x + game->player.plane.x
		* game->player.move_speed;
	new_y = game->player.position.y + game->player.plane.y
		* game->player.move_speed;
	if (game->level->map[(int)game->player.position.y][(int)new_x] != WALL)
		game->player.position.x = new_x;
	if (game->level->map[(int)new_y][(int)game->player.position.x] != WALL)
		game->player.position.y = new_y;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		destroy_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		strafe_left(game);
	else if (keycode == KEY_D)
		strafe_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
	return (0);
}
