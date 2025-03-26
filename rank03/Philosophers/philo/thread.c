/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:33:27 by nash              #+#    #+#             */
/*   Updated: 2025/03/26 16:13:03 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	while (1)
	{
		log_take_fork(philo);
		log_eat(philo);
		philo.state = EATING;
	}
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

void	join_threads(t_table table)
{
	int	i;

	i = 0;
	while (i < table.config.num_philos)
	{
		pthread_join(table.philos[i].tid, NULL);
		i++;
	}
}
