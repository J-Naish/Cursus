/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:56 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_str_arr(t_str_arr_heap str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	free_command(t_command *command)
{
	if (command->args)
		free_str_arr(command->args);
	if (command->input_file)
		free(command->input_file);
	if (command->output_file)
		free(command->output_file);
	if (command->heredoc_pipe != -1)
		close(command->heredoc_pipe);
	if (command->delimiter)
		free(command->delimiter);
	free(command);
}

void	free_pipelines(t_pipeline **pipelines)
{
	int	i;
	int	j;

	i = 0;
	while (pipelines[i])
	{
		j = 0;
		while (pipelines[i]->commands[j])
		{
			free_command(pipelines[i]->commands[j]);
			j++;
		}
		free(pipelines[i]->commands);
		free(pipelines[i]);
		i++;
	}
	free(pipelines);
}
