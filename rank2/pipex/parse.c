/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:54:39 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 23:21:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmds(int argc, char **argv)
{
	char	**strarr;
	int		i;

	strarr = (char **)malloc((argc - 2) * sizeof(char *));
	if (!strarr)
		return (NULL);
	i = 0;
	while (i < argc - 3)
	{
		strarr[i] = ft_strdup(argv[i + 2]);
		if (!strarr[i])
		{
			while (i > 0)
				free(strarr[i]);
			free(strarr);
			return (NULL);
		}
		i++;
	}
	strarr[i] = NULL;
	return (strarr);
}

char	*get_infilename(char **argv)
{
	char	*infilename;

	infilename = ft_strdup(argv[1]);
	if (!infilename)
		return (NULL);
}

char	*get_outfilename(int argc, char **argv)
{
	char	*outfilename;

	outfilename = ft_strdup(argv[argc - 1]);
	if (!outfilename)
		return (NULL);
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