/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:37:26 by nash              #+#    #+#             */
/*   Updated: 2025/03/10 02:19:08 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	log_take_fork(useconds_t timestamp, t_philo philo)
{
	printf("%d %d has taken a fork\n", timestamp, philo.number);
}

void	log_eat(useconds_t timestamp, t_philo philo)
{
	printf("%d %d is eating\n", timestamp, philo.number);
}

void	log_sleep(useconds_t timestamp, t_philo philo)
{
	printf("%d %d is sleeping\n", timestamp, philo.number);
}

void	log_think(useconds_t timestamp, t_philo philo)
{
	printf("%d %d is thinking\n", timestamp, philo.number);
}

void	log_died(useconds_t timestamp, t_philo philo)
{
	printf("%d %d died\n", timestamp, philo.number);
}
