/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:52 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:41:52 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>

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

typedef struct s_meta
{
	t_config		config;
	char			*sem_name_forks;
	sem_t			*sem_forks;
	char			*sem_name_log;
	sem_t			*sem_log;
	char			*sem_name_monitor;
	sem_t			*sem_monitor;
	char			*sem_name_eating_count;
	sem_t			*sem_eating_count;
	char			*sem_name_last_meal_time;
	sem_t			*sem_last_meal_time;
	struct timeval	start_time;
	pid_t			monitor_pid;
}	t_meta;

typedef enum e_philo_state
{
	THINKING = 0,
	SLEEPING = 1,
	EATING = 2,
}	t_philo_state;

typedef struct s_philo
{
	size_t			number;
	pid_t			pid;
	pthread_t		monitor_thread;
	t_philo_state	state;
	size_t			eating_count;
	struct timeval	last_meal_time;
	t_meta			*meta;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_meta			*meta;
}	t_table;

// MARK: parse/
// convert_to_sizet_bonus.c
size_t			convert_to_sizet(const char *s);
// init_bonus.c
t_table			*init_table(int argc, char **argv);
// validate_bonus.c
bool			is_valid_arg(int argc, char **argv);

// MARK: process/
// actions_bonus.c
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
// destroy_processes_bonus.c
void			destroy_processes(t_table *table, size_t i);
// log_bonus.c
void			log_take_fork(t_philo philo);
void			log_eat(t_philo philo);
void			log_sleep(t_philo philo);
void			log_think(t_philo philo);
// monitor_process_bonus.c
void			create_monitor_process(t_table *table);
// monitor_thread_bonus.c
void			create_monitor_thread(t_philo *philo);
// process_bonus.c
void			create_processes(t_table *table);

// MARK: utils/
// deinit_bonus.c
void			deinit_table(t_table *table);
// time_bonus.c
struct timeval	get_current_time(void);
int				get_elapsed_time(struct timeval start_time);
// unlink_sems_bonus.c
void			unlink_sems(t_meta meta);

#endif
