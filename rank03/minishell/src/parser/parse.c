/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:30 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:30 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static void	convert_dollar_tokens(t_token **tokens, char **envp)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		replace_dollar_word(tokens[i], envp);
		i++;
	}
}

static int	process_matched(t_token ***tokens, int pos, t_str_arr_heap matched)
{
	int	j;

	j = 1;
	while (matched && matched[j])
	{
		*tokens = insert_token(*tokens, create_token(matched[j],
					TOKEN_WORD, QUOTE_NONE), pos + j);
		j++;
	}
	return (j);
}

t_token	**convert_wildcard_tokens(t_token **tokens)
{
	t_str_arr_heap	matched;
	int				i;

	i = 0;
	while (tokens[i])
	{
		matched = get_matched_files(tokens[i]);
		if (matched && matched[0])
		{
			free(tokens[i]->value);
			tokens[i]->value = ft_strdup(matched[0]);
			i += process_matched(&tokens, i, matched);
		}
		else
			i++;
		if (matched)
			free_str_arr(matched);
	}
	return (tokens);
}

t_token	**parse(t_str_heap prompt, char **envp)
{
	t_token	**tokens;

	if (has_invalid_quote(prompt))
	{
		put_error(SHELL_NAME": invalid quote\n");
		g_signal.status = 1;
		return (NULL);
	}
	tokens = tokenize(prompt);
	if (!tokens)
	{
		put_error(SHELL_NAME": memory allocation error\n");
		g_signal.status = 1;
		return (NULL);
	}
	convert_dollar_tokens(tokens, envp);
	tokens = convert_wildcard_tokens(tokens);
	return (tokens);
}

// int main() {
// 	t_token **tokens;
// 	// test 1
// 	tokens = parse("'test");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 2
// 	tokens = parse("hello \" world");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 3
// 	tokens = parse("lorem ipsum 'dollar' sit");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 4
// 	tokens = parse("echo \"hello\" || wc");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 5
// 	tokens = parse("<< cat EOF | wc");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 6
// 	tokens = parse("echo $HOME");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 7
// 	tokens = parse("echo 'csd  cds$HOME'");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 8
// 	tokens = parse("echo $NONEXIST");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 9
// 	tokens = parse("echo $HOMEcnjdsk");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 10
// 	tokens = parse("echo $?cds");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 11
// 	tokens = parse("echo $?");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 12
// 	tokens = parse("echo cdsvsd$?csdcs");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 13
// 	tokens = parse("echo $USER");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 14
// 	tokens = parse("echo '$USER'");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 15
// 	tokens = parse("echo \"$USER\"");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// }