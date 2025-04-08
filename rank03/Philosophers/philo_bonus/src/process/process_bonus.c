/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:37 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 00:48:05 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

static void	routine(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	create_processes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid < 0)
		{
			destroy_processes(table, i);
			return ;
		}
		else if (table->philos[i].pid == 0)
		{
			create_monitor_thread(&(table->philos[i]));
			routine(&(table->philos[i]));
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	create_monitor_process(table);
	waitpid(-1, NULL, 0);
	destroy_processes(table, table->meta->config.num_philos);
	kill(table->meta->monitor_pid, SIGTERM);
	while (waitpid(-1, NULL, 0) > 0)
		;
}
