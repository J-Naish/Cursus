/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:41:35 by nash              #+#    #+#             */
/*   Updated: 2025/03/11 20:44:15 by nash             ###   ########.fr       */
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
# include <sys/time.h>
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

typedef struct t_fork
{
	int		number;
	bool	is_in_use;
}	t_fork;

typedef struct t_table
{
	t_philo			*philos;
	t_fork			*forks;
	t_config		config;
	struct timeval	start_time;
}	t_table;

void	print_config(t_config config);
void	print_philos(t_table table);
void	print_start_time(t_table table);

void	log_take_fork(struct timeval start_time, t_philo philo);
void	log_eat(struct timeval start_time, t_philo philo);
void	log_sleep(struct timeval start_time, t_philo philo);
void	log_sleep(struct timeval start_time, t_philo philo);
void	log_think(struct timeval start_time, t_philo philo);
void	log_died(struct timeval start_time, t_philo philo);

bool	is_valid_arg(int argc, char **argv);
t_table	init_table(int argc, char **argv);

void	deinit_table(t_table table);
int		get_elapsed_time(struct timeval start_time);

#endif