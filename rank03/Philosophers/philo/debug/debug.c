/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:33:09 by nash              #+#    #+#             */
/*   Updated: 2025/03/13 11:04:52 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_config(t_config config)
{
	printf("number_of_philosophers:                    %d\n",
		config.num_philos);
	printf("time_to_die:                               %d\n",
		config.time_to_die);
	printf("time_to_eat:                               %d\n",
		config.time_to_eat);
	printf("time_to_sleep:                             %d\n",
		config.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		config.times_to_eat_to_exit);
}

static char	*get_boolstr(bool b)
{
	if (b)
		return ("true");
	else
		return ("false");
}

void	print_philo(t_philo philo)
{
	printf("Philo %d\n", philo.number);
	printf("pthread_t                  : %ld\n", (long)philo.tid);
	printf("state                      : ");
	if (philo.state == THINKING)
		printf("thinking\n");
	else if (philo.state == SLEEPING)
		printf("sleeping\n");
	else if (philo.state == EATING)
		printf("eating\n");
	printf("is_dead                    : %s\n", get_boolstr(philo.is_dead));
	printf("is_full                    : %s\n", get_boolstr(philo.is_full));
	printf("eating_count               : %d\n", philo.eating_count);
	printf("elapsed time from last meal: %d\n",
		get_elapsed_time(philo.last_meal_time));
}

void	print_start_time(t_table table)
{
	printf("start time(tv_sec) : %ld\n", table.start_time.tv_sec);
	printf("start time(tv_usec): %d\n", table.start_time.tv_usec);
}
