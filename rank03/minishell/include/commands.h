#ifndef COMMANDS_H
# define COMMANDS_H

# include "./minishell.h"
# include "./types.h"

void	cmd_echo(t_str_arr str);

void	cmd_exit(t_str_arr_heap args);

#endif