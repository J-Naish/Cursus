/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 06:09:54 by nash              #+#    #+#             */
/*   Updated: 2025/03/03 09:23:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_arg(int argc, char **argv)
{
	size_t	len;

	if (argc == 1)
		arg_error("No map file specified.");
	else if (argc > 2)
		arg_error("Too many arguments.");
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		arg_error("File must have .ber extension.");
}
