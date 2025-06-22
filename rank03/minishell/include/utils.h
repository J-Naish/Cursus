/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:51:54 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:51:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./minishell.h"

char			*get_cmd_name(t_command *command);
bool			is_builtin_cmd(t_command *command);
bool			is_heredoc(t_command *command);

void			put_error(char *s);
void			command_not_found(const t_str command);
void			unable_to_execute(const t_str file_path);
void			system_error(void);
void			memory_allocation_failed(void);

void			free_tokens(t_token **tokens);
void			free_str_arr(t_str_arr_heap str_arr);
void			free_command(t_command *command);
void			free_pipelines(t_pipeline **pipelines);

char			*get_next_line(int fd);

int				get_command_count(t_pipeline *pipeline);

t_str_arr_heap	init_str_arr(void);
t_str_arr_heap	append_str(t_str_arr_heap str_arr, t_str str);
t_str_arr_heap	dup_str_arr(t_str_arr original);
t_str_heap		join_str_arr(t_str_arr str_arr, t_str connector);

bool			is_same_str(const char *s1, const char *s2);

bool			starts_with(const char *s, const char *prefix);

bool			includes(const char *s, char c);

bool			is_special_char(char c);

bool			is_space(char c);

bool			is_whitespace_only(const char *str);

bool			is_pipe(t_token *token);
bool			is_chain(t_token *token);
bool			is_word(t_token *token);
t_token			**insert_token(t_token **tokens, t_token *token, int position);

#endif