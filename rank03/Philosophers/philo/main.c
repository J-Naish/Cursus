/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:41:04 by nash              #+#    #+#             */
/*   Updated: 2025/03/10 01:30:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!is_valid_arg(argc, argv))
	{
		write(STDERR_FILENO, "Invalid args\n", 13);
		return (EXIT_FAILURE);
	}
	table = init_table(argc, argv);
	print_config(table.config);
	print_philos(table);
	cleanup_table(table);
	return (EXIT_SUCCESS);
}
