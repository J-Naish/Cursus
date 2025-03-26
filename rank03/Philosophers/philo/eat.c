/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:17:42 by nash              #+#    #+#             */
/*   Updated: 2025/03/26 18:30:05 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philo *philo)
{
	if ((*philo).state != THINKING)
		return ;
	if ((*philo).l_fork->is_in_use || (*philo).r_fork->is_in_use)
		return ;
	pthread_mutex_lock(&(*philo).l_fork->mutex);
	pthread_mutex_lock(&(*philo).r_fork->mutex);
	log_take_fork(*philo);
	log_eat(*philo);
	gettimeofday(&(*philo).last_meal_time, NULL);
	(*philo).state = EATING;
	(*philo).l_fork->is_in_use = true;
	(*philo).r_fork->is_in_use = true;
	pthread_mutex_unlock(&(*philo).l_fork->mutex);
	pthread_mutex_unlock(&(*philo).r_fork->mutex);
}
