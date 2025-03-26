/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:17:42 by nash              #+#    #+#             */
/*   Updated: 2025/03/26 20:06:12 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(*philo).l_fork->mutex);
	pthread_mutex_lock(&(*philo).r_fork->mutex);
	if ((*philo).l_fork->is_in_use || (*philo).r_fork->is_in_use)
	{
		pthread_mutex_unlock(&(*philo).r_fork->mutex);
		pthread_mutex_unlock(&(*philo).l_fork->mutex);
		return ;
	}
	(*philo).l_fork->is_in_use = true;
	(*philo).r_fork->is_in_use = true;
	log_take_fork(*philo);
	log_eat(*philo);
	gettimeofday(&(*philo).last_meal_time, NULL);
	(*philo).state = EATING;
	usleep((*philo).config.time_to_eat * 1000);
	(*philo).eating_count++;
	(*philo).l_fork->is_in_use = false;
	(*philo).r_fork->is_in_use = false;
	pthread_mutex_unlock(&(*philo).r_fork->mutex);
	pthread_mutex_unlock(&(*philo).l_fork->mutex);
}

static void	philo_sleep(t_philo *philo)
{
	(*philo).state = THINKING;
	log_sleep(*philo);
	usleep((*philo).config.time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	(*philo).state = THINKING;
	log_think(*philo);
}

void	routine(t_philo *philo)
{
	if ((*philo).state != THINKING)
		return ;
	philo_eat(philo);
	philo_sleep(philo);
	philo_think(philo);
}
