/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:26 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 00:47:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

void	log_take_fork(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(WHITE"%d %zu has taken a fork\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_eat(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(YELLOW"%d %zu is eating\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_sleep(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(CYAN"%d %zu is sleeping\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_think(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(GREEN"%d %zu is thinking\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}
