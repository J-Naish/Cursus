/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:48 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:41:48 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!is_valid_arg(argc, argv))
	{
		write(STDERR_FILENO, "Invalid args\n", 13);
		return (EXIT_FAILURE);
	}
	table = init_table(argc, argv);
	if (!table)
		exit(EXIT_FAILURE);
	create_processes(table);
	deinit_table(table);
	return (EXIT_SUCCESS);
}
