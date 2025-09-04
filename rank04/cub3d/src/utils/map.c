#include "../../include/cub3d.h"

bool	is_player(char c)
{
	if (c == PLAYER_N || c == PLAYER_S)
		return (true);
	else if (c == PLAYER_E || c == PLAYER_W)
		return (true);
	else
		return (false);
}

bool	is_empty(char c)
{
	if (c == EMPTY)
		return (true);
	else
		return (false);
}

bool	is_wall(char c)
{
	if (c == WALL)
		return (true);
	else
		return (false);
}

bool	is_void(char c)
{
	if (c == VOID)
		return (true);
	else
		return (false);
}

bool	is_map_symbol(char c)
{
	if (is_empty(c))
		return (true);
	else if (is_wall(c))
		return (true);
	else if (is_player(c))
		return (true);
	else if (is_void(c))
		return (true);
	else
		return (false);
}
