/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:59 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:41:00 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>

# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef WHITE
#  define WHITE "\033[37m"
# endif

# ifndef CYAN
#  define CYAN "\033[36m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef MAGENTA
#  define MAGENTA "\033[35m"
# endif

# ifndef RESET
#  define RESET "\033[0m"
# endif

typedef struct s_config
{
	size_t	num_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	times_to_eat_to_exit;
}	t_config;

typedef struct s_monitor
{
	pthread_t		tid;
	bool			is_simulating;
	pthread_mutex_t	mutex;
}	t_monitor;

typedef struct s_meta
{
	struct timeval	start_time;
	t_config		config;
	t_monitor		*monitor;
}	t_meta;

typedef struct s_fork
{
	size_t			number;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	size_t			number;
	size_t			eating_count;
	struct timeval	last_meal_time;
	pthread_t		tid;
	t_fork			*l_fork;
	t_fork			*r_fork;
	t_meta			*meta;
	pthread_mutex_t	mutex_last_meal_time;
	pthread_mutex_t	mutex_eating_count;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	t_fork	*forks;
	t_meta	*meta;
}	t_table;

// MARK: parse
// convert_to_sizet.c
size_t			convert_to_sizet(const char *s);
// init.c
t_table			*init_table(int argc, char **argv);
// validate.c
bool			is_valid_arg(int argc, char **argv);

// MARK: thread
// actions.c
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
// helpers.c
bool			should_simulation_stop(t_monitor *monitor);
void			split_sleep(size_t duration, t_monitor *monitor);
// log.c
void			log_take_fork(t_philo *philo);
void			log_eat(t_philo *philo);
void			log_sleep(t_philo *philo);
void			log_think(t_philo *philo);
void			log_die(t_philo *philo);
// monitor.c
bool			is_one_of_philos_starving(t_table *table);
bool			have_all_philos_eaten_enough(t_table *table);
// thread.c
void			create_threads(t_table *table);

// MARK: utils
// deinit.c
void			deinit_table(t_table *table);
// time.c
struct timeval	get_current_time(void);
int				get_elapsed_time(struct timeval start_time);

#endif
