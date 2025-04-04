/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:46 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:40:47 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (should_simulation_stop(philo->meta->monitor))
			return (NULL);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	(void)table;
	while (1)
	{
		if (is_one_of_philos_starving(table))
		{
			pthread_mutex_lock(&(table->meta->monitor->mutex));
			table->meta->monitor->is_simulating = false;
			pthread_mutex_unlock(&(table->meta->monitor->mutex));
			return (NULL);
		}
		if (have_all_philos_eaten_enough(table))
		{
			pthread_mutex_lock(&(table->meta->monitor->mutex));
			table->meta->monitor->is_simulating = false;
			pthread_mutex_unlock(&(table->meta->monitor->mutex));
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

void	create_threads(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_create(&(table->philos[i].tid), NULL,
			routine, &(table->philos[i]));
		i++;
	}
	pthread_create(&(table->meta->monitor->tid), NULL, monitor_routine, table);
	pthread_join(table->meta->monitor->tid, NULL);
	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_join(table->philos[i].tid, NULL);
		i++;
	}
}
