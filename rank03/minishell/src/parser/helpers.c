/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:28 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static bool	is_unclosed_quote(t_str_heap *prompt_ptr, char quote)
{
	(*prompt_ptr)++;
	while (**prompt_ptr && **prompt_ptr != quote)
		(*prompt_ptr)++;
	if (!**prompt_ptr)
		return (true);
	return (false);
}

bool	has_invalid_quote(t_str_heap prompt)
{
	if (!ft_strchr(prompt, '\'') && !ft_strchr(prompt, '\"'))
		return (false);
	while (*prompt)
	{
		if (*prompt == '\'')
		{
			if (is_unclosed_quote(&prompt, '\''))
				return (true);
		}
		else if (*prompt == '\"')
		{
			if (is_unclosed_quote(&prompt, '\"'))
				return (true);
		}
		prompt++;
	}
	return (false);
}

int	next_quote_index(t_str_heap prompt, char quote)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == quote)
			break ;
		i++;
	}
	return (i);
}

int	next_index(t_str_heap prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]) || is_special_char(prompt[i]))
			break ;
		i++;
	}
	return (i);
}
