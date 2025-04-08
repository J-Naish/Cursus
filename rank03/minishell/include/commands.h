#ifndef COMMANDS_H
# define COMMANDS_H

# include "./minishell.h"
# include "./types.h"

typedef enum e_echo_option
{
	N,
	NONE
}	t_echo_option;

void	cmd_echo(t_str_arr str, t_echo_option option);

#endif