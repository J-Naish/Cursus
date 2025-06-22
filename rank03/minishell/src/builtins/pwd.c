/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:19 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:19 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	cmd_pwd(t_command *command)
{
	char	*cwd;
	char	buffer[PATH_MAX];

	if (command->args[1] && starts_with(command->args[1], "-")
		&& ft_strlen(command->args[1]) > 1)
		put_error(SHELL_NAME": no option is available\n");
	cwd = getcwd(buffer, sizeof(buffer));
	if (!cwd)
		perror(SHELL_NAME": ");
	ft_putstr_fd(cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

// int main() {
// 	t_command	*command;
// 	command = create_test_command("pwd");
// 	cmd_pwd(command);
// 	free_command(command);
// }