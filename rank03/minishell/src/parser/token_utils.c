/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:38 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:38 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_token	**init_tokens(void)
{
	t_token	**tokens;

	tokens = (t_token **)malloc(sizeof(t_token *));
	if (!tokens)
		return (NULL);
	*tokens = NULL;
	return (tokens);
}

t_token	*create_token(char *value,
		t_token_type type, t_token_quote quote)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->value = ft_strdup(value);
	token->type = type;
	token->quote = quote;
	return (token);
}

static int	get_tokens_size(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

t_token	**append_token(t_token **tokens,
		char *value, t_token_type type, t_token_quote quote)
{
	t_token	**new_tokens;
	t_token	*new_token;
	int		size;

	size = get_tokens_size(tokens);
	new_token = create_token(value, type, quote);
	new_tokens = insert_token(tokens, new_token, size);
	return (new_tokens);
}

// int main() {
// 	t_token	**tokens;
// 	tokens = NULL;
// 	print_tokens(tokens);
// 	tokens = init_tokens();
// 	print_tokens(tokens);
// 	tokens = append_token(tokens, "echo", TOKEN_WORD, QUOTE_NONE);
// 	print_tokens(tokens);
// 	tokens = append_token(tokens, "hello world", TOKEN_WORD, SINGLE_QUOTE);
// 	tokens = append_token(tokens, "|", TOKEN_REDIRECT, QUOTE_NONE);
// 	tokens = append_token(tokens, "wc", TOKEN_WORD, QUOTE_NONE);
// 	print_tokens(tokens);
// 	free_tokens(tokens);
// }