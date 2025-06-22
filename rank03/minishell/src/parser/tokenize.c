/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:40 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:40 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static void	append_quoted_word(t_token ***tokens,
	t_str_heap prompt, int *i, char quote)
{
	int				length;
	t_str_heap		temp;
	t_token_quote	quote_type;

	if (quote == '\'')
		quote_type = SINGLE_QUOTE;
	else if (quote == '\"')
		quote_type = DOUBLE_QUOTE;
	else
		quote_type = QUOTE_NONE;
	(*i)++;
	length = next_quote_index(&prompt[*i], quote);
	temp = ft_substr(prompt, *i, (size_t)length);
	*tokens = append_token(*tokens, temp, TOKEN_WORD, quote_type);
	free(temp);
	*i += length + 1;
}

static void	append_special_char(t_token ***tokens, t_str_heap prompt, int *i)
{
	int				length;
	t_str_heap		temp;
	t_token_type	type;

	length = 1;
	if (prompt[*i] == prompt[*i + 1])
		length += 1;
	if (prompt[*i] == '&')
		type = TOKEN_CHAIN;
	else if (prompt[*i] == '|' && prompt[*i + 1] == '|')
		type = TOKEN_CHAIN;
	else
		type = TOKEN_REDIRECT;
	temp = ft_substr(prompt, *i, (size_t)length);
	*tokens = append_token(*tokens, temp, type, QUOTE_NONE);
	free(temp);
	*i += length;
}

static void	append_regular_word(t_token ***tokens, t_str_heap prompt, int *i)
{
	int			length;
	t_str_heap	temp;

	length = next_index(&prompt[*i]);
	temp = ft_substr(prompt, *i, (size_t)length);
	*tokens = append_token(*tokens, temp, TOKEN_WORD, QUOTE_NONE);
	free(temp);
	*i += length;
}

t_token	**tokenize(t_str_heap prompt)
{
	t_token		**tokens;
	int			i;

	tokens = init_tokens();
	if (!tokens)
		return (NULL);
	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]))
			i++;
		else if (prompt[i] == '\'')
			append_quoted_word(&tokens, prompt, &i, '\'');
		else if (prompt[i] == '\"')
			append_quoted_word(&tokens, prompt, &i, '\"');
		else if (is_special_char(prompt[i]))
			append_special_char(&tokens, prompt, &i);
		else
			append_regular_word(&tokens, prompt, &i);
	}
	return (tokens);
}

// int main() {
// 	t_token **test;
// 	test = tokenize("echo hello world");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo \"hello world\"");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo 'hello world'");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo \"it's a test\" 'of tokenize function'");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo	\n 'hello	world'    a	");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo||hello");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo|&hello");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = tokenize("echo|&hello");
// 	print_tokens(test);
// 	free_tokens(test);
// }