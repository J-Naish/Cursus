/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:51:36 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:51:36 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGER_H
# define DEBUGGER_H

# include "./minishell.h"

void		print_bool(bool b);

void		print_command(t_command *command);

void		print_number(int n);

void		print_pipelines(t_pipeline **pipelines);

void		print_str_arr(const t_str_arr str_arr);

void		print_str(const t_str str);

void		print_token(t_token *token);
void		print_tokens(t_token **tokens);

#endif