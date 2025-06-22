/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:51:26 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:51:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "./minishell.h"

void	cmd_cd(t_command *command, char ***envpp);

void	cmd_echo(t_command *command);

void	cmd_env(t_command *command, char ***envpp);

void	cmd_exit(t_command *command);

bool	is_same_key(char *new_env, char *env);
bool	env_key_exists(char *new_env, char **envp);
bool	is_valid_format(char *new_env);
char	*get_env_value(char *key, char **envpp);
void	cmd_export(t_command *command, char ***envpp);

void	cmd_pwd(t_command *command);

void	cmd_unset(t_command *command, char ***envpp);

#endif