/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:06 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:06 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

int	handle_single_builtin(t_pipeline *pipeline, char ***envpp)
{
	if (get_command_count(pipeline) == 1
		&& is_builtin_cmd(pipeline->commands[0]))
	{
		if (is_same_str(pipeline->commands[0]->args[0], "exit"))
			cmd_exit(pipeline->commands[0]);
		run_command(pipeline->commands[0], envpp);
		return (EXIT_SUCCESS);
	}
	return (-1);
}

void	create_pipe_if_needed(t_pipe_context *ctx, t_command **commands)
{
	if (commands[ctx->command_index + 1]
		&& pipe(ctx->pipe_fds[ctx->active_pipe]) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
}

pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	execute_command_loop(t_pipeline *pipeline, char ***envpp,
							pid_t *last_pid)
{
	t_pipe_context		pipe_ctx;
	t_process_context	proc_ctx;
	pid_t				pid;

	pipe_ctx.active_pipe = 0;
	pipe_ctx.command_index = 0;
	proc_ctx.pipe_ctx = &pipe_ctx;
	proc_ctx.pipeline = pipeline;
	proc_ctx.envpp = envpp;
	while (pipeline->commands[pipe_ctx.command_index])
	{
		create_pipe_if_needed(&pipe_ctx, pipeline->commands);
		pid = fork_process();
		if (pid == 0)
			handle_child_process(&proc_ctx);
		else
		{
			handle_parent_process(&pipe_ctx, pid, last_pid, pipeline->commands);
			pipe_ctx.command_index++;
			pipe_ctx.active_pipe = (pipe_ctx.active_pipe + 1) % 2;
		}
	}
}

int	execute_pipeline(t_pipeline *pipeline, char ***envpp)
{
	int		builtin_result;
	pid_t	last_pid;

	builtin_result = handle_single_builtin(pipeline, envpp);
	if (builtin_result != -1)
		return (builtin_result);
	execute_command_loop(pipeline, envpp, &last_pid);
	return (wait_for_pipeline(last_pid));
}
