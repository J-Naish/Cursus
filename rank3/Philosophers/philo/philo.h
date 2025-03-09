/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:41:35 by nash              #+#    #+#             */
/*   Updated: 2025/03/10 04:14:35 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <time.h>
# include <sys/types.h>
# include <pthread.h>

typedef struct t_config
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat_to_exit;
}	t_config;

typedef struct t_philo
{
	int	number;
}	t_philo;

typedef struct t_table
{
	t_philo		*philos;
	t_config	config;
}	t_table;

void	print_config(t_config config);
void	print_philos(t_table table);

void	log_take_fork(int timestamp, t_philo philo);
void	log_eat(int timestamp, t_philo philo);
void	log_sleep(int timestamp, t_philo philo);
void	log_sleep(int timestamp, t_philo philo);
void	log_think(int timestamp, t_philo philo);
void	log_died(int timestamp, t_philo philo);

bool	is_valid_arg(int argc, char **argv);
t_table	init_table(int argc, char **argv);

void	cleanup_table(t_table table);

#endif