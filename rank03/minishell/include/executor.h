/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:51:38 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:57:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./minishell.h"

t_pipeline	**build_pipeline(t_token **tokens);

t_command	*create_command(t_token **tokens, int start, int end);
t_command	**append_command(t_command **command_arr, t_command *command);

void		execute(t_pipeline **pipelines, char ***envpp);

void		heredoc(t_command *command);

t_pipeline	*init_pipeline(void);
t_pipeline	**init_pipeline_arr(void);
t_pipeline	**append_pipeline(t_pipeline **pl_arr, t_pipeline *pl);

void		save_std_fds(int saved_fds[2]);
void		restore_std_fds(int saved_fds[2]);
bool		setup_input_redirect(t_command *command);
bool		setup_output_redirect(t_command *command);

void		run_command(t_command *command, char ***envpp);

bool		validate_tokens(t_token **tokens);

int			handle_single_builtin(t_pipeline *pipeline, char ***envpp);
void		create_pipe_if_needed(t_pipe_context *ctx, t_command **commands);
pid_t		fork_process(void);
void		execute_command_loop(t_pipeline *pipeline, char ***envpp,
				pid_t *last_pid);
int			execute_pipeline(t_pipeline *pipeline, char ***envpp);
void		handle_child_process(t_process_context *proc_ctx);
void		handle_parent_process(t_pipe_context *ctx, pid_t pid,
				pid_t *last_pid, t_command **commands);
int			wait_for_pipeline(pid_t last_pid);

#endif