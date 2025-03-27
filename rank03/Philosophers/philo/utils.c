/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:29:48 by nash              #+#    #+#             */
/*   Updated: 2025/03/28 00:43:26 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_elapsed_time(struct timeval start_time)
{
	struct timeval	now;
	int				sec_diff;
	int				usec_diff;
	int				elapsed;

	gettimeofday(&now, NULL);
	sec_diff = now.tv_sec - start_time.tv_sec;
	usec_diff = now.tv_usec - start_time.tv_usec;
	elapsed = sec_diff * 1000 + usec_diff / 1000;
	return (elapsed);
}

bool	is_philo_starving(t_philo philo)
{
	return (get_elapsed_time(philo.last_meal_time) >= philo.config.time_to_die
		&& philo.state != EATING);
}

void	split_sleep(int duration)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (get_elapsed_time(start) < duration)
		usleep(1000);
}
