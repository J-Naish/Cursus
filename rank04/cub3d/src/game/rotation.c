#include "../../include/cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rot;
	double	sin_rot;

	cos_rot = cos(-game->player.rot_speed);
	sin_rot = sin(-game->player.rot_speed);
	old_dir_x = game->player.direction.x;
	game->player.direction.x = game->player.direction.x * cos_rot
		- game->player.direction.y * sin_rot;
	game->player.direction.y = old_dir_x * sin_rot
		+ game->player.direction.y * cos_rot;
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos_rot
		- game->player.plane.y * sin_rot;
	game->player.plane.y = old_plane_x * sin_rot
		+ game->player.plane.y * cos_rot;
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rot;
	double	sin_rot;

	cos_rot = cos(game->player.rot_speed);
	sin_rot = sin(game->player.rot_speed);
	old_dir_x = game->player.direction.x;
	game->player.direction.x = game->player.direction.x * cos_rot
		- game->player.direction.y * sin_rot;
	game->player.direction.y = old_dir_x * sin_rot
		+ game->player.direction.y * cos_rot;
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos_rot
		- game->player.plane.y * sin_rot;
	game->player.plane.y = old_plane_x * sin_rot
		+ game->player.plane.y * cos_rot;
}
