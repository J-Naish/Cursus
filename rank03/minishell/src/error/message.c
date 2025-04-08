#include "../../include/error.h"

void	command_not_found(const t_str command)
{
	ft_putstr_fd(SHELL_NAME": command not found: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_COMMAND_NOT_FOUND);
}

void	unable_to_execute(const t_str file_path)
{
	ft_putstr_fd(SHELL_NAME": ", STDERR_FILENO);
	ft_putstr_fd(strerror(EACCES), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(file_path, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_UNABLE_TO_EXECUTE);
}

// int main() {
// 	// command_not_found("non_existing_command");
// 	// unable_to_execute("./test");
// }