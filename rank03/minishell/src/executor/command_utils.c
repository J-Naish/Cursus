/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:56 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:56 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static t_command	*init_command(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->args = init_str_arr();
	command->is_redirect = false;
	command->input_file = NULL;
	command->output_file = NULL;
	command->append_output = false;
	command->heredoc_pipe = -1;
	command->delimiter = NULL;
	return (command);
}

static void	handle_redirect(t_command *command, t_token **tokens, int idx)
{
	command->is_redirect = true;
	if ((tokens[idx + 1] && tokens[idx + 1]->type != TOKEN_WORD))
		return ;
	if (!tokens[idx + 1])
		return ;
	if (is_same_str(tokens[idx]->value, ">"))
		command->output_file = ft_strdup(tokens[idx + 1]->value);
	else if (is_same_str(tokens[idx]->value, "<"))
		command->input_file = ft_strdup(tokens[idx + 1]->value);
	else if (is_same_str(tokens[idx]->value, ">>"))
	{
		command->output_file = ft_strdup(tokens[idx + 1]->value);
		command->append_output = true;
	}
	else if (is_same_str(tokens[idx]->value, "<<"))
		command->delimiter = ft_strdup(tokens[idx + 1]->value);
}

t_command	*create_command(t_token **tokens, int start, int end)
{
	t_command	*command;
	int			i;

	command = init_command();
	if (!command)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		if (tokens[start + i]->type == TOKEN_REDIRECT)
		{
			handle_redirect(command, tokens, start + i);
			i++;
		}
		else
		{
			command->args = append_str(command->args, tokens[start + i]->value);
		}
		i++;
	}
	return (command);
}

t_command	**append_command(t_command **command_arr, t_command *command)
{
	int			i;
	t_command	**new;

	i = 0;
	while (command_arr[i])
		i++;
	new = (t_command **)malloc(sizeof(t_command *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (command_arr[i])
	{
		new[i] = command_arr[i];
		i++;
	}
	new[i] = command;
	new[i + 1] = NULL;
	free(command_arr);
	return (new);
}

// int main() {
// 	// test 1
// 	t_token **tokens = tokenize("echo 'hello world'");
// 	t_command *command = create_command(tokens, 0, 2);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 2
// 	tokens = tokenize("ls > log.txt");
// 	command = create_command(tokens, 0, 3);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 3
// 	tokens = tokenize("sort < input.txt");
// 	command = create_command(tokens, 0, 3);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 4
// 	tokens = tokenize("echo 'new line' >> log.txt");
// 	command = create_command(tokens, 0, 4);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 5
// 	tokens = tokenize("cat << EOF");
// 	command = create_command(tokens, 0, 3);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 6
// 	tokens = tokenize("cat < input.txt > output.txt");
// 	command = create_command(tokens, 0, 5);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 7
// 	tokens = tokenize("grep -i 'pattern' < file.txt > results.txt");
// 	command = create_command(tokens, 0, 7);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 8
// 	tokens = tokenize("echo hello >");
// 	command = create_command(tokens, 0, 3);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// 	// test 9
// 	tokens = tokenize("ls -la /home /usr /var");
// 	command = create_command(tokens, 0, 5);
// 	print_command(command);
// 	free_tokens(tokens);
// 	free_command(command);
// }