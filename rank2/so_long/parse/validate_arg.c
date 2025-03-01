/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 06:09:54 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 08:12:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_arg(int argc, char **argv)
{
	size_t	len;

	if (argc == 1)
		map_error("No map file specified.");
	else if (argc > 2)
		map_error("Too many arguments.");
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		map_error("File must have .ber extension.");
}
