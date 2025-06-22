/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:37 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:37 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debugger.h"

static void	print_chain(t_chain_operator operator)
{
	ft_putstr_fd("    operator: ", STDOUT_FILENO);
	if (operator == CHAIN_AND)
		ft_putstr_fd(YELLOW"AND"RESET"(&&)", STDOUT_FILENO);
	else if (operator == CHAIN_OR)
		ft_putstr_fd(YELLOW"OR"RESET"(||)", STDOUT_FILENO);
	else
		ft_putstr_fd(BLACK"undefined"RESET, STDOUT_FILENO);
}

static void	print_single_command(t_command *command)
{
	if (!command)
	{
		ft_putstr_fd("      ", STDOUT_FILENO);
		print_str(NULL);
		return ;
	}
	ft_putstr_fd("      {\n", STDOUT_FILENO);
	ft_putstr_fd("        args         : ", STDOUT_FILENO);
	print_str_arr(command->args);
	ft_putstr_fd(",\n        is redirect  : ", STDOUT_FILENO);
	print_bool(command->is_redirect);
	ft_putstr_fd(",\n        input file   : ", STDOUT_FILENO);
	print_str(command->input_file);
	ft_putstr_fd(",\n        output file  : ", STDOUT_FILENO);
	print_str(command->output_file);
	ft_putstr_fd(",\n        append output: ", STDOUT_FILENO);
	print_bool(command->append_output);
	ft_putstr_fd(",\n        heredoc pipe : ", STDOUT_FILENO);
	print_number(command->heredoc_pipe);
	ft_putstr_fd(",\n        delimiter    : ", STDOUT_FILENO);
	print_str(command->delimiter);
	ft_putstr_fd("\n      }", STDOUT_FILENO);
}

static void	print_commands(t_command **commands)
{
	int	i;

	ft_putstr_fd("    commands: ", STDOUT_FILENO);
	if (!commands)
	{
		print_str(NULL);
		print_str(",\n");
		return ;
	}
	i = 0;
	ft_putstr_fd("[\n", STDOUT_FILENO);
	while (commands[i])
	{
		print_single_command(commands[i]);
		ft_putstr_fd(",\n", STDOUT_FILENO);
		i++;
	}
	print_single_command(commands[i]);
	ft_putstr_fd("\n    ],\n", STDOUT_FILENO);
}

static void	print_pipeline(t_pipeline *pipeline)
{
	if (!pipeline)
	{
		print_str(NULL);
		ft_putstr_fd("\n", STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("  {\n", STDOUT_FILENO);
	print_commands(pipeline->commands);
	print_chain(pipeline->operator);
	ft_putstr_fd("\n  }", STDOUT_FILENO);
}

void	print_pipelines(t_pipeline **pipelines)
{
	int	i;

	if (!pipelines)
	{
		print_str(NULL);
		ft_putstr_fd("\n", STDOUT_FILENO);
		return ;
	}
	i = 0;
	ft_putstr_fd("[\n", STDOUT_FILENO);
	while (pipelines[i])
	{
		print_pipeline(pipelines[i]);
		ft_putstr_fd(",\n", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("  ", STDOUT_FILENO);
	print_pipeline(pipelines[i]);
	ft_putstr_fd("]\n", STDOUT_FILENO);
}

// int main() {
// 	t_command **commands = malloc(sizeof(t_command *) * 4);
// 	t_token **tokens1 = tokenize("echo hello world");
// 	t_token **tokens2 = tokenize("ls -la > log.txt");
// 	t_token **tokens3 = tokenize("cat >> EOF");
// 	commands[0] = create_command(tokens1, 0, 2);
// 	commands[1] = create_command(tokens2, 0, 3);
// 	commands[2] = create_command(tokens3, 0, 2);
// 	commands[3] = NULL;
// 	t_pipeline **pipelines;
// 	pipelines = (t_pipeline **)malloc(sizeof(t_pipeline *) * 2);
// 	pipelines[0] = (t_pipeline *)malloc(sizeof(t_pipeline));
// 	pipelines[0]->commands = commands;
// 	pipelines[0]->operator = CHAIN_AND;
// 	print_pipelines(pipelines);
// 	free_pipelines(pipelines);
// 	free_tokens(tokens1);
// 	free_tokens(tokens2);
// 	free_tokens(tokens3);
// }