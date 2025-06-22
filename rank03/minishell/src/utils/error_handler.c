/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:54 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	put_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
}

void	command_not_found(const t_str command)
{
	put_error(SHELL_NAME": ");
	put_error(command);
	put_error(": command not found\n");
	exit(EXIT_NOT_FOUND);
}

void	unable_to_execute(const t_str file_path)
{
	put_error(SHELL_NAME": ");
	put_error(strerror(EACCES));
	put_error(": ");
	put_error(file_path);
	put_error("\n");
	exit(EXIT_UNABLE_TO_EXECUTE);
}

void	system_error(void)
{
	perror(SHELL_NAME);
	exit(EXIT_FAILURE);
}

void	memory_allocation_failed(void)
{
	errno = ENOMEM;
	system_error();
}

// int main() {
// 	// command_not_found("non_existing_command");
// 	// unable_to_execute("./test");
// 	// memory_allocation_failed();
// 	exit(EXIT_FAILURE);
// }