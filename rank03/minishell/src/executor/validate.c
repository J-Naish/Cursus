/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:16 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:16 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/executor.h"

static void	put_token_syntax_error(t_token *invalid_token)
{
	put_error(SHELL_NAME": syntax error near unexpected token `");
	put_error(invalid_token->value);
	put_error("'");
	put_error("\n");
}

static bool	starts_with_pipe_or_chain(t_token **tokens)
{
	if (is_pipe(tokens[0]) || is_chain(tokens[0]))
		return (true);
	else
		return (false);
}

static bool	end_with_word(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i == 0)
		return (false);
	if (is_word(tokens[i - 1]))
		return (true);
	else
		return (false);
}

bool	validate_tokens(t_token **tokens)
{
	int	i;

	if (!tokens)
		return (false);
	if (starts_with_pipe_or_chain(tokens))
		return (put_token_syntax_error(tokens[0]), false);
	if (!end_with_word(tokens))
		return (put_error(SHELL_NAME": syntax error at the end\n"), false);
	i = 1;
	while (tokens[i])
	{
		if (!is_word(tokens[i]) && !is_word(tokens[i - 1]))
			return (put_token_syntax_error(tokens[i]), false);
		i++;
	}
	return (true);
}

// int main() {
// 	t_token **tokens;
// 	// test 1: true
// 	tokens = tokenize("echo hello world");
// 	print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	free_tokens(tokens);
// 	// test 2: true
// 	tokens = tokenize("ls -la | grep .txt");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 3: true
// 	tokens = tokenize("cat < input.txt > output.txt");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 4: true
// 	tokens = tokenize("mkdir test && cd test || echo 'failed'");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 5: false
// 	tokens = tokenize("| echo hello");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 6: false
// 	tokens = tokenize("&& echo hello");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 7: false
// 	tokens = tokenize("echo hello |");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 8: false
// 	tokens = tokenize("echo hello &&");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 9: true
// 	tokens = tokenize("echo hello '&&'");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 10: false
// 	tokens = tokenize("ls | | grep txt");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 11: false
// 	tokens = tokenize("echo hello && || echo world");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 12: false
// 	tokens = tokenize("ls > | grep txt");
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// 	// test 13: true
// 	char *t;
// 	t="cat file.txt|grep pattern|sort|uniq>results.txt&&echo 'done'";
// 	tokens=tokenize(t);
//     print_bool(validate_tokens(tokens));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
//     free_tokens(tokens);
// }