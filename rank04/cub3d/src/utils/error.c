#include "../../include/cub3d.h"

void	put_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

void	exit_with_error_msg(char *msg)
{
	put_error(msg);
	exit(EXIT_FAILURE);
}
