/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:29 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 00:48:00 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

static void	routine(t_table *table)
{
	size_t	finished_count;

	finished_count = 0;
	while (finished_count < table->meta->config.num_philos)
	{
		sem_wait(table->meta->sem_monitor);
		finished_count++;
	}
}

void	create_monitor_process(t_table *table)
{
	table->meta->monitor_pid = fork();
	if (table->meta->monitor_pid < 0)
	{
		destroy_processes(table, table->meta->config.num_philos);
	}
	else if (table->meta->monitor_pid == 0)
	{
		routine(table);
		sem_wait(table->meta->sem_log);
		printf(MAGENTA"All the philosophers have eaten enough times\n"RESET);
		exit(EXIT_FAILURE);
	}
}
