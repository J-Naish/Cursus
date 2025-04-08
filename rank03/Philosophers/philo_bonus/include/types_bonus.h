#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# include "./philo_bonus.h"

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

#endif
