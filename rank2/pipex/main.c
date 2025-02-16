/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 03:29:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	char	*infilefd;
	char	*outfilefd;
	char	**cmds;

	if (argc < 5)
		return (0);
	infilefd = open(argv[1], O_RDONLY);
	if (infilefd < 0)
		puterrno();
	outfilefd = open(argv[argc - 1], O_RDONLY);
	if (outfilefd < 0)
		puterrno();
	return (0);
}
