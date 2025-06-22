/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:42 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:42 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debugger.h"

static bool	is_escape_char(char c)
{
	if (c == '\a' || c == '\b' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == '\e')
		return (true);
	else
		return (false);
}

static char	deescape(char c)
{
	if (c == '\a')
		return ('a');
	else if (c == '\b')
		return ('b');
	else if (c == '\t')
		return ('t');
	else if (c == '\n')
		return ('n');
	else if (c == '\v')
		return ('v');
	else if (c == '\f')
		return ('f');
	else if (c == '\r')
		return ('r');
	else if (c == '\e')
		return ('e');
	else
		return (c);
}

void	print_str(const t_str str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd(BOLD"null"RESET, STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd(GREEN"\'", STDOUT_FILENO);
	while (str[i])
	{
		if (!is_escape_char(str[i]))
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(YELLOW"\\", STDOUT_FILENO);
			ft_putchar_fd(deescape(str[i]), STDOUT_FILENO);
			ft_putstr_fd(GREEN, STDOUT_FILENO);
		}
		i++;
	}
	ft_putstr_fd("\'"RESET, STDOUT_FILENO);
}

// int main() {
// 	print_str("test");
// 	printf("\n");
// 	print_str("lorem ipsum");
// 	printf("\n");
// 	print_str("it's a test");
// 	printf("\n");
// 	print_str("hello	world");
// 	printf("\n");
// 	print_str("");
// 	printf("\n");
// 	print_str("test case \nnew line");
// 	printf("\n");
// 	print_str(NULL);
// 	printf("\n");
// }