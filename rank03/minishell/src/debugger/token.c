/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:44 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:44 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debugger.h"

static void	print_token_type(t_token_type token_type)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	if (token_type == TOKEN_WORD)
		ft_putstr_fd("WORD", STDOUT_FILENO);
	else if (token_type == TOKEN_REDIRECT)
		ft_putstr_fd("REDIRECT", STDOUT_FILENO);
	else if (token_type == TOKEN_CHAIN)
		ft_putstr_fd("CHAIN", STDOUT_FILENO);
	else
		ft_putstr_fd(BLACK"undefined", STDOUT_FILENO);
	ft_putstr_fd(RESET, STDOUT_FILENO);
}

static void	print_token_quote(t_token_quote quote)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	if (quote == SINGLE_QUOTE)
		ft_putstr_fd("SINGLE", STDOUT_FILENO);
	else if (quote == DOUBLE_QUOTE)
		ft_putstr_fd("DOUBLE", STDOUT_FILENO);
	else if (quote == QUOTE_NONE)
		ft_putstr_fd("NONE", STDOUT_FILENO);
	else
		ft_putstr_fd(BLACK"undefined", STDOUT_FILENO);
	ft_putstr_fd(RESET, STDOUT_FILENO);
}

void	print_token(t_token *token)
{
	if (!token)
	{
		ft_putstr_fd(BOLD"null\n"RESET, STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("{ type: ", STDOUT_FILENO);
	print_token_type(token->type);
	ft_putstr_fd(", value: "GREEN"'", STDOUT_FILENO);
	ft_putstr_fd(token->value, STDOUT_FILENO);
	ft_putstr_fd("'"RESET, STDOUT_FILENO);
	ft_putstr_fd(", quote: ", STDOUT_FILENO);
	print_token_quote(token->quote);
	ft_putstr_fd(" }", STDOUT_FILENO);
}

void	print_tokens(t_token **tokens)
{
	int	i;

	if (!tokens)
	{
		ft_putstr_fd(BOLD"null\n"RESET, STDOUT_FILENO);
		return ;
	}
	i = 0;
	ft_putstr_fd("[\n", STDOUT_FILENO);
	while (tokens[i])
	{
		ft_putstr_fd("  ", STDOUT_FILENO);
		print_token(tokens[i]);
		ft_putstr_fd(",\n", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("  "BOLD"null"RESET"\n]\n", STDOUT_FILENO);
}

// int main() {
// 	t_token	token;
// 	token.value = "test";
// 	token.type = TOKEN_REDIRECT;
// 	token.quote = SINGLE_QUOTE;
// 	print_token(&token);
// }