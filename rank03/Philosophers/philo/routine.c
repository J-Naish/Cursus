/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:17:42 by nash              #+#    #+#             */
/*   Updated: 2025/03/28 00:49:30 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_fork(t_philo *philo)
{
	if ((*philo).number % 2 == 0)
	{
		pthread_mutex_lock(&(*philo).r_fork->mutex);
		log_take_fork(*philo);
		pthread_mutex_lock(&(*philo).l_fork->mutex);
		log_take_fork(*philo);
	}
	else
	{
		pthread_mutex_lock(&(*philo).l_fork->mutex);
		log_take_fork(*philo);
		pthread_mutex_lock(&(*philo).r_fork->mutex);
		log_take_fork(*philo);
	}
}

void	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	log_eat(*philo);
	philo->state = EATING;
	usleep((*philo).config.time_to_eat * 1000);
	(*philo).eating_count++;
	if ((*philo).number % 2 == 0)
	{
		pthread_mutex_unlock(&(*philo).l_fork->mutex);
		pthread_mutex_unlock(&(*philo).r_fork->mutex);
	}
	else
	{
		pthread_mutex_unlock(&(*philo).r_fork->mutex);
		pthread_mutex_unlock(&(*philo).l_fork->mutex);
	}
	gettimeofday(&(*philo).last_meal_time, NULL);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	log_sleep(*philo);
	split_sleep(philo->config.time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	log_think(*philo);
}
