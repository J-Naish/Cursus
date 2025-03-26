/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:03:26 by nash              #+#    #+#             */
/*   Updated: 2025/03/27 05:40:23 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (table->simulation_running)
	{
		i = 0;
		while (i < table->config.num_philos)
		{
			if (is_philo_starving(table->philos[i]))
			{
				table->philos[i].state = DEAD;
				log_died(table->philos[i]);
				table->simulation_running = false;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	create_monitor_thread(t_table *table)
{
	pthread_create(&(*table).monitor_tid, NULL, monitor_routine, table);
}

void	join_monitor_thread(t_table *table)
{
	pthread_join((*table).monitor_tid, NULL);
}
