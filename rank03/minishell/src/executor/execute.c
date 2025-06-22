/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:58 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:58 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static void	process_all_heredoc(t_pipeline **pipelines)
{
	int	i;
	int	j;

	i = 0;
	while (pipelines[i])
	{
		j = 0;
		while (pipelines[i]->commands[j])
		{
			if (is_heredoc(pipelines[i]->commands[j]))
				heredoc(pipelines[i]->commands[j]);
			j++;
		}
		i++;
	}
}

static bool	should_execute_pipeline(int i, int last_status,
							t_pipeline **pipelines)
{
	t_chain_operator	prev_op;

	if (i == 0)
		return (true);
	prev_op = pipelines[i - 1]->operator;
	if (prev_op == CHAIN_AND && last_status != 0)
		return (false);
	else if (prev_op == CHAIN_OR && last_status == 0)
		return (false);
	return (true);
}

static void	execute_all_pipelines(t_pipeline **pipelines, char ***envpp)
{
	int		i;
	int		last_status;

	i = 0;
	last_status = 0;
	while (pipelines[i])
	{
		if (should_execute_pipeline(i, last_status, pipelines))
			last_status = execute_pipeline(pipelines[i], envpp);
		i++;
	}
	g_signal.status = last_status;
}

void	execute(t_pipeline **pipelines, char ***envpp)
{
	setup_execution_signals();
	process_all_heredoc(pipelines);
	execute_all_pipelines(pipelines, envpp);
	setup_signals();
}
