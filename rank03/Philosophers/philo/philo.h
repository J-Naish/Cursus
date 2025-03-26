/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:41:35 by nash              #+#    #+#             */
/*   Updated: 2025/03/26 18:27:34 by nash             ###   ########.fr       */
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

typedef struct s_config
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat_to_exit;
}	t_config;

typedef enum e_philo_state
{
	THINKING = 0,
	SLEEPING = 1,
	EATING = 2
}	t_philo_state;

typedef struct s_fork
{
	int				number;
	bool			is_in_use;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				number;
	t_philo_state	state;
	int				eating_count;
	struct timeval	last_meal_time;
	struct timeval	start_time;
	t_config		config;
	pthread_t		tid;
	t_fork			*l_fork;
	t_fork			*r_fork;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_fork			*forks;
	t_config		config;
	struct timeval	start_time;
}	t_table;

void	print_config(t_config config);
void	print_philo(t_philo philo);
void	print_table(t_table table);
void	print_start_time(t_table table);

void	log_take_fork(t_philo philo);
void	log_eat(t_philo philo);
void	log_sleep(t_philo philo);
void	log_sleep(t_philo philo);
void	log_think(t_philo philo);
void	log_died(t_philo philo);

bool	is_valid_arg(int argc, char **argv);
t_table	init_table(int argc, char **argv);

void	deinit_table(t_table *table);
int		get_elapsed_time(struct timeval start_time);

void	create_threads(t_table *table);
void	join_threads(t_table *table);

void	start_eat(t_philo *philo);

#endif