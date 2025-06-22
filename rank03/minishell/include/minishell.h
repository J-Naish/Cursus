/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:51:42 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:56:04 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <limits.h>
# include "../libft/libft.h"
# include "./types.h"
# include "./builtins.h"
# include "./constants.h"
# include "./debugger.h"
# include "./executor.h"
# include "./misc.h"
# include "./parser.h"
# include "./utils.h"

extern t_signal	g_signal;

t_str_arr_heap	init_shell(int argc, char **argv, char **envp);
t_str_heap		read_and_validate_prompt(void);
t_token			**parse_and_validate(t_str_heap prompt,
					t_str_arr_heap local_env);
void			execute_pipeline_cycle(t_token **tokens,
					t_str_arr_heap *local_env);
void			init_signal(void);

#endif