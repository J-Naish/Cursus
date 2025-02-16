/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:54:39 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 23:39:26 by nash             ###   ########.fr       */
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
	return (infilename);
}

char	*get_outfilename(int argc, char **argv)
{
	char	*outfilename;

	outfilename = ft_strdup(argv[argc - 1]);
	if (!outfilename)
		return (NULL);
	return (outfilename);
}

// int main(int argc, char **argv) {
// 	char *infilename = get_infilename(argv);
// 	char *outfilename = get_outfilename(argc, argv);
// 	char **cmds = get_cmds(argc, argv);
// 	printf("infile name is: %s\n", infilename);
// 	printf("outfile name is: %s\n", outfilename);
// 	int i = 0;
// 	while (cmds[i])
// 	{
// 		printf("cmd %d is: %s\n", i + 1, cmds[i]);
// 		i++;
// 	}
// 	return 0;
// }