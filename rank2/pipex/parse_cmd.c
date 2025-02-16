/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:54:39 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 23:11:00 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmds(int argc, char **argv)
{
	char	**strarr;
	int		i;
	char	*str;

	strarr = (char **)malloc((argc - 3) * sizeof(char *));
	if (!strarr)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc - 3)
	{
		strarr[i] = argv[i + 2];
		i++;
	}
	return (strarr);
}

// int main() {
// 	char *argv1[] = {
// 		"./pipex",
// 		"infile",
// 		"ls -l",
// 		"grep a1",
// 		"outfile"
// 	};
// 	char **cmds1 = get_cmds(5, argv1);
// 	printf("%s\n", cmds1[0]);
// 	printf("%s\n\n", cmds1[1]);

// 	char *argv2[] = {
// 		"./pipex",
// 		"infile",
// 		"ls -l",
// 		"grep a1",
// 		"cat",
// 		"echo",
// 		"cd",
// 		"mkdir",
// 		"vim",
// 		"outfile"
// 	};
// 	char **cmds2 = get_cmds(10, argv2);
// 	printf("%s\n", cmds2[0]);
// 	printf("%s\n", cmds2[1]);
// 	printf("%s\n", cmds2[2]);
// 	printf("%s\n", cmds2[3]);
// 	printf("%s\n", cmds2[4]);
// 	printf("%s\n", cmds2[5]);
// 	printf("%s\n", cmds2[6]);
// 	return 0;
// }