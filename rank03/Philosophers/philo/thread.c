/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:33:27 by nash              #+#    #+#             */
/*   Updated: 2025/03/25 21:09:21 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	(void)philo;
	return (NULL);
}

void	create_threads(t_table table)
{
	int			i;

	i = 0;
	while (i < table.config.num_philos)
	{
		pthread_create(&table.philos[i].tid, NULL,
			start_routine, &table.philos[i]);
		print_philo(table.philos[i]);
		i++;
	}
}
