/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:33:27 by nash              #+#    #+#             */
/*   Updated: 2025/03/26 23:36:32 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine(t_philo *philo)
{
	philo_die(philo);
	philo_eat(philo);
	philo_sleep(philo);
	philo_think(philo);
}

static void	*start_routine(void *arg)
{
	t_philo	philo;

	philo = *((t_philo *)arg);
	while (1)
	{
		routine(&philo);
	}
	return (NULL);
}

void	create_threads(t_table *table)
{
	int			i;

	i = 0;
	while (i < (*table).config.num_philos)
	{
		pthread_create(&(*table).philos[i].tid, NULL,
			start_routine, &(*table).philos[i]);
		i++;
	}
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < (*table).config.num_philos)
	{
		pthread_join((*table).philos[i].tid, NULL);
		i++;
	}
}
