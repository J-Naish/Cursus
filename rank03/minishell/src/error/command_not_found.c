#include "../../include/error.h"

void	command_not_found(const t_str command)
{
	ft_putstr_fd(SHELL_NAME": command not found: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_COMMAND_NOT_FOUND);
}

// int main() {
// 	command_not_found("non_existing_command");
// }