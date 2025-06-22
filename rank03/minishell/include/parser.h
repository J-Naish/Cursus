/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:51:47 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:51:47 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "./minishell.h"

bool			has_invalid_quote(t_str_heap prompt);
int				next_quote_index(t_str_heap prompt, char quote);
int				next_index(t_str_heap prompt);

t_str_arr_heap	get_matched_files(t_token *token);

void			replace_dollar_word(t_token *token, char **envp);

t_token			**parse(t_str_heap prompt, char **envp);

t_token			**tokenize(t_str_heap prompt);

t_token			**init_tokens(void);
t_token			*create_token(char *value,
					t_token_type type, t_token_quote quote);
t_token			**append_token(t_token **tokens,
					char *value, t_token_type type, t_token_quote quote);

#endif