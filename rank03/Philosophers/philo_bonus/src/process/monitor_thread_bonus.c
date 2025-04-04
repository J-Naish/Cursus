#include "../philo_bonus.h"

static bool	is_starving(t_philo *philo)
{
	sem_wait(philo->meta->sem_last_meal_time);
	if ((size_t)get_elapsed_time(philo->last_meal_time)
		>= philo->meta->config.time_to_die)
	{
		sem_post(philo->meta->sem_last_meal_time);
		return (true);
	}
	else
	{
		sem_post(philo->meta->sem_last_meal_time);
		return (false);
	}
}

static void	declare_death(t_philo *philo)
{
	sem_wait(philo->meta->sem_log);
	printf(RED"%d %zu died\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
	exit(EXIT_SUCCESS);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	bool	has_eaten_enough;

	philo = (t_philo *)arg;
	has_eaten_enough = false;
	while (1)
	{
		if (is_starving(philo))
			declare_death(philo);
		if (!has_eaten_enough)
		{
			sem_wait(philo->meta->sem_eating_count);
			if (philo->eating_count >= philo->meta->config.times_to_eat_to_exit)
			{
				has_eaten_enough = true;
				sem_post(philo->meta->sem_monitor);
			}
			sem_post(philo->meta->sem_eating_count);
		}
		usleep(1000);
	}
	return (NULL);
}

void	create_monitor_thread(t_philo *philo)
{
	pthread_create(&(philo->monitor_thread), NULL, routine, philo);
	pthread_detach(philo->monitor_thread);
}
