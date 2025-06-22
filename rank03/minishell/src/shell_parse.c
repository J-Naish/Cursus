/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:54:27 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:54:52 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	**parse_and_validate(t_str_heap prompt, t_str_arr_heap local_env)
{
	t_token	**tokens;

	tokens = parse(prompt, local_env);
	if (!validate_tokens(tokens))
	{
		if (tokens)
			free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}

void	execute_pipeline_cycle(t_token **tokens, t_str_arr_heap *local_env)
{
	t_pipeline	**pipelines;

	pipelines = build_pipeline(tokens);
	free_tokens(tokens);
	execute(pipelines, local_env);
	rl_on_new_line();
	free_pipelines(pipelines);
}
