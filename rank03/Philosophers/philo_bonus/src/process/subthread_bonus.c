#include "../philo_bonus.h"

static bool	is_starving(t_philo philo)
{
	if (philo.state == EATING)
		return (false);
	if ((size_t)get_elapsed_time(philo.last_meal_time)
		>= philo.meta->config.time_to_die)
		return (true);
	else
		return (false);
}

static bool	has_eaten_enough(t_philo philo)
{
	if (philo.eating_count >= philo.meta->config.times_to_eat_to_exit)
		return (true);
	else
		return (false);
}

static void	*monitor_thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (is_starving(*philo))
		{
			log_died(*philo);
			exit(EXIT_SUCCESS);
		}
		if (has_eaten_enough(*philo))
			exit(EXIT_SUCCESS);
		usleep(1000);
	}
	return (NULL);
}

int	create_monitor_thread(t_philo *philo)
{
	int	result;

	result = pthread_create(&(philo->subthread), NULL,
			monitor_thread_routine, philo);
	if (result == -1)
		return (-1);
	pthread_detach(philo->subthread);
	return (0);
}
