/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:02:36 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 01:39:14 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit();
	return (fd);
}

int	open_outfile(const char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		error_exit();
	return (fd);
}

char	**get_cmd_args(char const *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error_exit();
	return (cmd_args);
}

// int main() {
// 	char **test =
// 		get_cmd_args("cc -Wall -Wextra -Werror");
// 	printf("%s\n", test[0]);
// 	printf("%s\n", test[1]);
// 	printf("%s\n", test[2]);
// 	printf("%s\n", test[3]);
// 	printf("%s\n", test[4]);
// }