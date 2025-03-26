/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:37:26 by nash              #+#    #+#             */
/*   Updated: 2025/03/27 00:24:32 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_take_fork(t_philo philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	printf("%d %d has taken a fork\n",
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_eat(t_philo philo)
{
	printf("%d %d is eating\n",
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_sleep(t_philo philo)
{
	printf("%d %d is sleeping\n",
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_think(t_philo philo)
{
	printf("%d %d is thinking\n",
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_died(t_philo philo)
{
	printf("\033[31m%d %d died\n\033[0m",
		get_elapsed_time(philo.start_time), philo.number);
}
