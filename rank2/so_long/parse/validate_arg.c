/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 06:09:54 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 06:17:34 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_arg(int argc, char **argv)
{
	size_t	len;

	if (argc == 1)
	{
		ft_putstr_fd("Error: No map file specified. ", STDERR_FILENO);
		ft_putstr_fd("Please provide a .ber file.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Error: Too many arguments. ", STDERR_FILENO);
		ft_putstr_fd("Please provide only one .ber file.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: File must have .ber extension\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
