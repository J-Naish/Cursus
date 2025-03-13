/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:33:27 by nash              #+#    #+#             */
/*   Updated: 2025/03/13 09:50:40 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*start_routine(void *arg)
{
	t_table	table;

	table = *((t_table *)arg);
	(void)table;
	return (NULL);
}

void	create_threads(t_table table)
{
	int			i;
	pthread_t	tids[table.config.num_philos];

	i = 0;
	while (i < table.config.num_philos)
	{
		pthread_create(&tids[i], NULL, start_routine, &table);
		i++;
	}
}
