/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:37 by nash              #+#    #+#             */
/*   Updated: 2025/04/14 13:41:34 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

static void	delay_routine(t_philo *philo)
{
	if (philo->meta->config.num_philos == 1)
		return ;
	if (philo->number > philo->meta->config.num_philos / 2)
		usleep(1000 * philo->meta->config.time_to_eat);
}

static void	routine(t_philo *philo)
{
	delay_routine(philo);
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
