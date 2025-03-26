/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:41:04 by nash              #+#    #+#             */
/*   Updated: 2025/03/26 16:07:23 by nash             ###   ########.fr       */
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
	create_threads(table);
	
	// Wait for all philosopher threads to finish
	int i;
	for (i = 0; i < table.config.num_philos; i++)
	{
		pthread_join(table.philos[i].tid, NULL);
	}
	
	deinit_table(table);
	return (EXIT_SUCCESS);
}
