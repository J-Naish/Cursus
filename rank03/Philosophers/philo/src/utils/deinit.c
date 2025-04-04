/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:51 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:40:51 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	destroy_mutexes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_mutex_destroy(&(table->forks[i].mutex));
		pthread_mutex_destroy(&(table->philos[i].mutex_last_meal_time));
		pthread_mutex_destroy(&(table->philos[i].mutex_eating_count));
		i++;
	}
	pthread_mutex_destroy(&(table->meta->monitor->mutex));
}

void	deinit_table(t_table *table)
{
	destroy_mutexes(table);
	free(table->philos);
	free(table->forks);
	free(table->meta->monitor);
	free(table->meta);
	free(table);
}
