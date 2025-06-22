/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:08 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:55:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static void	setup_child_pipes(t_pipe_context *ctx)
{
	int	prev_pipe;

	if (ctx->command_index != 0)
	{
		prev_pipe = (ctx->active_pipe + 1) % 2;
		dup2(ctx->pipe_fds[prev_pipe][0], STDIN_FILENO);
		close(ctx->pipe_fds[prev_pipe][0]);
		close(ctx->pipe_fds[prev_pipe][1]);
	}
}

static void	setup_child_output(t_pipe_context *ctx, t_command **commands)
{
	if (commands[ctx->command_index + 1])
	{
		dup2(ctx->pipe_fds[ctx->active_pipe][1], STDOUT_FILENO);
		close(ctx->pipe_fds[ctx->active_pipe][0]);
		close(ctx->pipe_fds[ctx->active_pipe][1]);
	}
}

void	handle_child_process(t_process_context *proc_ctx)
{
	setup_child_pipes(proc_ctx->pipe_ctx);
	setup_child_output(proc_ctx->pipe_ctx, proc_ctx->pipeline->commands);
	run_command(proc_ctx->pipeline->commands[proc_ctx->pipe_ctx->command_index],
		proc_ctx->envpp);
	exit(EXIT_FAILURE);
}

void	handle_parent_process(t_pipe_context *ctx, pid_t pid,
							pid_t *last_pid, t_command **commands)
{
	int	prev_pipe;

	if (!commands[ctx->command_index + 1])
		*last_pid = pid;
	if (ctx->command_index != 0)
	{
		prev_pipe = (ctx->active_pipe + 1) % 2;
		close(ctx->pipe_fds[prev_pipe][0]);
		close(ctx->pipe_fds[prev_pipe][1]);
	}
}

int	wait_for_pipeline(pid_t last_pid)
{
	int	status;

	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
