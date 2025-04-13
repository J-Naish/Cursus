#ifndef TYPES_H
# define TYPES_H

# include "./philo.h"

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
	pthread_mutex_t	mutex_log;
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

#endif
