/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:21 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 00:47:48 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

static void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->meta->sem_forks);
	log_take_fork(*philo);
	sem_wait(philo->meta->sem_forks);
	log_take_fork(*philo);
}

void	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	philo->state = EATING;
	log_eat(*philo);
	sem_wait(philo->meta->sem_last_meal_time);
	philo->last_meal_time = get_current_time();
	sem_post(philo->meta->sem_last_meal_time);
	usleep(1000 * philo->meta->config.time_to_eat);
	sem_wait(philo->meta->sem_eating_count);
	philo->eating_count += 1;
	sem_post(philo->meta->sem_eating_count);
	sem_post(philo->meta->sem_forks);
	sem_post(philo->meta->sem_forks);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	log_sleep(*philo);
	usleep(1000 * philo->meta->config.time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	log_think(*philo);
}
