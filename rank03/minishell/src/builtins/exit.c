#include "../../include/builtins.h"

void	cmd_exit(t_command *command)
{
	if (!is_same_str(command->args[0], "exit"))
		return ;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (command->args[1])
	{
		ft_putstr_fd(SHELL_NAME": exit: ", STDERR_FILENO);
		ft_putstr_fd(command->args[1], STDERR_FILENO);
		ft_putstr_fd(": no option is available\n", STDERR_FILENO);
		free_command(command);
		exit(2);
	}
	free_command(command);
	exit(EXIT_SUCCESS);
}
