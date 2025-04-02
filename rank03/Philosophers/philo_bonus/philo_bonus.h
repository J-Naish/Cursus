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
# include <stdbool.h>
# include <stdint.h>

# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef CYAN
#  define CYAN "\033[36m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
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

typedef enum e_philo_state
{
	THINKING = 0,
	SLEEPING = 1,
	EATING = 2,
}	t_philo_state;

typedef struct s_philo
{
	pid_t			pid;
	t_philo_state	state;
	size_t			eating_count;
	struct timeval	last_meal_time;
}	t_philo;

typedef struct s_table
{
	sem_t	sem_fork;
}	t_table;

// validate_bonus.c
bool	is_valid_arg(int argc, char **argv);

#endif