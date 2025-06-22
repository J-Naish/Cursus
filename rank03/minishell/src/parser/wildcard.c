/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:43 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:53:43 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static bool	find_matching(char *p, char *s, char *asterisk, char *start)
{
	while (*s)
	{
		if (*p == '*')
		{
			asterisk = p++;
			start = s;
			continue ;
		}
		if (*p == *s)
		{
			p++;
			s++;
			continue ;
		}
		if (asterisk)
		{
			p = asterisk + 1;
			s = ++start;
			continue ;
		}
		return (false);
	}
	while (*p == '*')
		p++;
	return (*p == '\0');
}

static bool	match_pattern(char *pattern, char *str)
{
	char	*p;
	char	*s;
	char	*asterisk;
	char	*start;

	if (is_same_str(pattern, "*"))
		return (true);
	p = pattern;
	s = str;
	asterisk = NULL;
	start = NULL;
	return (find_matching(p, s, asterisk, start));
}

static t_str_arr_heap	collect_matches(DIR *dir, t_str pattern)
{
	struct dirent	*entry;
	t_str			filename;
	t_str_arr_heap	matches;

	matches = init_str_arr();
	entry = readdir(dir);
	while (entry)
	{
		filename = entry->d_name;
		if (filename[0] == '.' && pattern[0] != '.')
		{
			entry = readdir(dir);
			continue ;
		}
		if (match_pattern(pattern, filename))
			matches = append_str(matches, filename);
		entry = readdir(dir);
	}
	return (matches);
}

t_str_arr_heap	get_matched_files(t_token *token)
{
	DIR				*dir;
	t_str_arr_heap	matches;

	if (token->quote != QUOTE_NONE || !includes(token->value, '*'))
		return (NULL);
	dir = opendir(".");
	if (!dir)
		return (NULL);
	matches = collect_matches(dir, token->value);
	closedir(dir);
	return (matches);
}

// int main() {
// 	print_bool(match_pattern("*.c", "file.c"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("test*", "testfile"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("a*b*c", "abc"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("a*b*c", "abxyzc"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("a*b", "axxc"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// }