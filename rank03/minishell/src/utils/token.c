/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:54:11 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:54:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

bool	is_pipe(t_token *token)
{
	if (token->type == TOKEN_REDIRECT && is_same_str(token->value, "|"))
		return (true);
	else
		return (false);
}

bool	is_chain(t_token *token)
{
	if (token->type == TOKEN_CHAIN)
		return (true);
	else
		return (false);
}

bool	is_word(t_token *token)
{
	if (token->type == TOKEN_WORD)
		return (true);
	else
		return (false);
}

t_token	**insert_token(t_token **tokens, t_token *token, int position)
{
	int			length;
	int			i;
	int			j;
	t_token		**new;

	length = 0;
	while (tokens[length])
		length++;
	new = (t_token **)malloc(sizeof(t_token *) * (length + 2));
	i = 0;
	j = 0;
	while (j <= length)
	{
		if (j == position)
			new[j] = token;
		else
			new[j] = tokens[i++];
		j++;
	}
	new[j] = NULL;
	free(tokens);
	return (new);
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
// 	tokens = insert_token(tokens,
// 		create_token("test", TOKEN_WORD, QUOTE_NONE), 1);
// 	print_tokens(tokens);
// 	free_tokens(tokens);
// }