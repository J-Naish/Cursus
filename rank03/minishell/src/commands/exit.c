#include "../../include/commands.h"

void	cmd_exit(t_str_arr_heap args)
{
	if (!is_same_str(args[0], "exit"))
		return ;
	if (args[1])
	{
		ft_putstr_fd(SHELL_NAME": exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putstr_fd(": no option is available\n", STDERR_FILENO);
		free_str_arr(args);
		// TODO: promptをfree
		exit(2);
	}
	exit(EXIT_SUCCESS);
}
