/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:03 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:03 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->commands = (t_command **)malloc(sizeof(t_command *));
	if (!pipeline->commands)
		return (free(pipeline), NULL);
	pipeline->commands[0] = NULL;
	pipeline->operator = CHAIN_UNDEFINED;
	return (pipeline);
}

t_pipeline	**init_pipeline_arr(void)
{
	t_pipeline	**pipeline_arr;

	pipeline_arr = (t_pipeline **)malloc(sizeof(t_pipeline *) * 2);
	if (!pipeline_arr)
		return (NULL);
	pipeline_arr[0] = init_pipeline();
	if (!pipeline_arr[0])
		return (free(pipeline_arr), NULL);
	pipeline_arr[1] = NULL;
	return (pipeline_arr);
}

t_pipeline	**append_pipeline(t_pipeline **pl_arr, t_pipeline *pl)
{
	int			i;
	t_pipeline	**new;

	i = 0;
	while (pl_arr[i])
		i++;
	new = (t_pipeline **)malloc(sizeof(t_pipeline *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (pl_arr[i])
	{
		new[i] = pl_arr[i];
		i++;
	}
	new[i] = pl;
	new[i + 1] = NULL;
	free(pl_arr);
	return (new);
}
