/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:29:48 by nash              #+#    #+#             */
/*   Updated: 2025/03/27 04:10:41 by nash             ###   ########.fr       */
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

void	custom_sleep(int duration, t_philo *philo)
{
	int	slept;
	int	unit;

	slept = 0;
	unit = SLEEP_UNIT;
	while (slept <= duration)
	{
		if (slept + unit < duration)
			usleep(unit * 1000);
		else
			usleep((duration - slept) * 1000);
		if (is_philo_starving(*philo))
		{
			philo->state = DEAD;
			log_died(*philo);
			break ;
		}
		slept += unit;
	}
}
