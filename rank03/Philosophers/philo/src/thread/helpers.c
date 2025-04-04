/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:37 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:40:38 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	should_simulation_stop(t_monitor *monitor)
{
	bool	b;

	pthread_mutex_lock(&(monitor->mutex));
	b = monitor->is_simulating;
	pthread_mutex_unlock(&(monitor->mutex));
	return (!b);
}

void	split_sleep(size_t duration, t_monitor *monitor)
{
	struct timeval	start;

	start = get_current_time();
	while ((size_t)get_elapsed_time(start) < duration)
	{
		if (should_simulation_stop(monitor))
			return ;
		usleep(1000);
	}
}
