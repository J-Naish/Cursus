/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:54:31 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:54:49 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_str_heap	read_and_validate_prompt(void)
{
	t_str_heap	prompt;

	prompt = readline(SHELL_NAME"$ ");
	if (!prompt)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!*prompt || is_whitespace_only(prompt))
	{
		free(prompt);
		return (NULL);
	}
	add_history(prompt);
	return (prompt);
}
