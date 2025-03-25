/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:25:30 by nash              #+#    #+#             */
/*   Updated: 2025/03/25 22:37:46 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deinit_table(t_table table)
{
	int	i;

	free(table.philos);
	i = 0;
	while (i < table.config.num_philos)
	{
		pthread_mutex_destroy(&table.forks[i].mutex);
		i++;
	}
	free(table.forks);
}
