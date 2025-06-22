/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:36 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:36 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static int	get_chunk_length(t_str s)
{
	int	i;

	i = 0;
	if (s[0] == '$')
	{
		while (s[i] && !is_space(s[i]))
		{
			if (s[i + 1] && s[i + 1] == '?')
				return (2);
			i++;
		}
	}
	else if (is_space(s[0]))
	{
		while (s[i] && is_space(s[i]))
			i++;
	}
	else
	{
		while (s[i] && !is_space(s[i]) && s[i] != '$')
			i++;
	}
	return (i);
}

static int	chunk_count(t_str s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_space(s[i]))
		{
			count++;
			i += get_chunk_length(&s[i]);
		}
		else
		{
			count++;
			i += get_chunk_length(&s[i]);
		}
	}
	return (count);
}

static t_str_arr_heap	split_words(t_str s)
{
	t_str_arr_heap	chunks;
	int				size;
	int				i;
	int				j;
	int				length;

	size = chunk_count(s);
	chunks = (t_str_arr_heap)malloc(sizeof(t_str_heap) * (size + 1));
	if (!chunks)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		length = get_chunk_length(&s[i]);
		chunks[j] = ft_substr(s, i, length);
		if (!chunks[j])
			return (free_str_arr(chunks), NULL);
		i += length;
		j++;
	}
	chunks[j] = NULL;
	return (chunks);
}

static void	convert_dollar_word(t_str_heap *word, char **envp)
{
	t_str		env_var;
	t_str_heap	new;

	if (is_same_str(*word, "$?"))
	{
		new = ft_itoa(g_signal.status);
	}
	else if (starts_with(*word, "$") && ft_strlen(*word) > 1)
	{
		env_var = get_env_value((*word) + 1, envp);
		if (env_var)
			new = ft_strdup(env_var);
		else
			new = ft_strdup("");
	}
	else
		return ;
	free(*word);
	*word = new;
}

void	replace_dollar_word(t_token *token, char **envp)
{
	t_str_arr_heap	splitted;
	int				i;

	if (token->quote == SINGLE_QUOTE)
		return ;
	splitted = split_words(token->value);
	i = 0;
	while (splitted[i])
	{
		convert_dollar_word(&splitted[i], envp);
		i++;
	}
	free(token->value);
	token->value = join_str_arr(splitted, NULL);
	free_str_arr(splitted);
}

// int main() {
// 	printf("%d\n", chunk_count(" he   l 	llo ") == 7);
// 	printf("%d\n", chunk_count("$SHELL test    hello 	$?") == 7);
// 	printf("%d\n", chunk_count(" ") == 1);
// 	printf("%d\n", chunk_count("hello") == 1);
// 	printf("%d\n", chunk_count("hello world") == 3);
// 	printf("%d\n", chunk_count("echo test$SHELL") == 4);
// 	printf("%d\n", chunk_count("test$SHELLvdsav") == 2);
// 	printf("%d\n", chunk_count("test$?test") == 3);
// 	printf("%d\n", chunk_count("$? ") == 2);
// 	printf("%d\n", chunk_count("$?") == 1);
// 	printf("%d\n", chunk_count("echo $?") == 3);
// }
// int main() {
// 	char **test;
// 	// test 1
// 	test = split_words(" he   l 	llo ");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 2
// 	test = split_words("$SHELL test    hello 	$?");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 3
// 	test = split_words(" ");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 4
// 	test = split_words("hello");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 5
// 	test = split_words("hello world");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 6
// 	test = split_words("echo cnsdkj$SHELLcsn");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 7
// 	test = split_words("echo cnsdkj$?csn");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// }