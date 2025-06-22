/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:31 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:31 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debugger.h"

static void	print_command_fields(t_command *command)
{
	ft_putstr_fd("{\n", STDOUT_FILENO);
	ft_putstr_fd("  args         : ", STDOUT_FILENO);
	print_str_arr(command->args);
	ft_putstr_fd(",\n", STDOUT_FILENO);
	ft_putstr_fd("  is redirect  : ", STDOUT_FILENO);
	print_bool(command->is_redirect);
	ft_putstr_fd(",\n", STDOUT_FILENO);
	ft_putstr_fd("  input file   : ", STDOUT_FILENO);
	print_str(command->input_file);
	ft_putstr_fd(",\n", STDOUT_FILENO);
	ft_putstr_fd("  output file  : ", STDOUT_FILENO);
	print_str(command->output_file);
	ft_putstr_fd(",\n", STDOUT_FILENO);
	ft_putstr_fd("  append output: ", STDOUT_FILENO);
	print_bool(command->append_output);
	ft_putstr_fd(",\n", STDOUT_FILENO);
	ft_putstr_fd("  heredoc pipe : ", STDOUT_FILENO);
	print_number(command->heredoc_pipe);
	ft_putstr_fd(",\n", STDOUT_FILENO);
	ft_putstr_fd("  delimiter    : ", STDOUT_FILENO);
	print_str(command->delimiter);
	ft_putstr_fd("\n}\n", STDOUT_FILENO);
}

void	print_command(t_command *command)
{
	if (!command)
	{
		print_str(NULL);
		ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	print_command_fields(command);
}

// int main() {
// 	// test case 1
// 	t_command cmd1 = {0};
// 	char *args1[] = {"ls", "-la", "/home", NULL};
// 	cmd1.args = args1;
// 	print_command(&cmd1);
// 	// test case 2
// 	t_command cmd2 = {0};
//     char *args2[] = {"grep", "pattern", NULL};
//     cmd2.args = args2;
// 	cmd2.is_redirect = true;
//     cmd2.input_file = "input.txt";
//     print_command(&cmd2);
// 	// test case 3
// 	t_command cmd3 = {0};
//     char *args3[] = {"echo", "Hello world", NULL};
//     cmd3.args = args3;
// 	cmd3.is_redirect = true;
//     cmd3.output_file = "output.log";
//     cmd3.append_output = true;
//     print_command(&cmd3);
// 	// test case 4
// 	t_command cmd4 = {0};
//     char *args4[] = {"cat", NULL};
// 	cmd4.is_redirect = true;
//     cmd4.args = args4;
//     cmd4.heredoc = "This is a\nheredoc content\nwith multiple lines.";
// 	cmd4.delimiter = "EOF";
//     print_command(&cmd4);
// 	// test case 5
// 	t_command cmd5 = {0};
//     char *args5[] = {"sed", "s/old/new/g", NULL};
// 	cmd5.is_redirect = true;
//     cmd5.args = args5;
//     cmd5.input_file = "input.txt";
//     cmd5.output_file = "processed.txt";
//     cmd5.append_output = false;
//     cmd5.heredoc = NULL;
//     print_command(&cmd5);
// 	// test case 6
// 	t_command cmd6 = {0};
//     char *args6[] = {NULL};
//     cmd6.args = args6;
//     print_command(&cmd6);
// 	// test case 7
// 	t_command *cmd7 = NULL;
// 	print_command(cmd7);
// }