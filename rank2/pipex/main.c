/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 02:45:09 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	char	*infilename;
	char	*outfilename;
	char	**cmds;

	if (argc < 5)
		return (0);
	infilename = get_infilename(argv);
	if (!infilename)
		return (EXIT_FAILURE);
	outfilename = get_outfilename(argc, argv);
	if (!outfilename)
		return (free(infilename), EXIT_FAILURE);
	cmds = get_cmds(argc, argv);
	if (!cmds)
		return (free(infilename), free(outfilename), EXIT_FAILURE);
	open_infile(infilename, outfilename, cmds);
	free_all(infilename, outfilename, cmds);
	return (0);
}
