/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:50:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 03:35:49 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	infilefd;
	int	outfilefd;

	if (argc < 5)
		return (0);
	infilefd = open(argv[1], O_RDONLY);
	if (infilefd < 0)
		error_exit();
	outfilefd = open(argv[argc - 1], O_RDONLY);
	if (outfilefd < 0)
		error_exit();
	return (0);
}
