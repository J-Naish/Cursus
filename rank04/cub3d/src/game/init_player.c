#include "../../include/cub3d.h"

static void	set_player_direction(t_player *player, char orientation)
{
	player->direction.x = 0;
	player->direction.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
	if (orientation == PLAYER_N)
	{
		player->direction.y = -1;
		player->plane.x = 0.66;
	}
	else if (orientation == PLAYER_S)
	{
		player->direction.y = 1;
		player->plane.x = -0.66;
	}
	else if (orientation == PLAYER_E)
	{
		player->direction.x = 1;
		player->plane.y = 0.66;
	}
	else if (orientation == PLAYER_W)
	{
		player->direction.x = -1;
		player->plane.y = -0.66;
	}
}

void	init_player(t_player *player, t_level *level)
{
	int	x;
	int	y;

	y = 0;
	while (level->map[y])
	{
		x = 0;
		while (level->map[y][x])
		{
			if (is_player(level->map[y][x]))
			{
				player->position.x = x + 0.5;
				player->position.y = y + 0.5;
				set_player_direction(player, level->map[y][x]);
				player->move_speed = 0.05;
				player->rot_speed = 0.03;
				level->map[y][x] = EMPTY;
				return ;
			}
			x++;
		}
		y++;
	}
}
