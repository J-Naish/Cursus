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

static void	*death_monitor_routine(void *arg)
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
		usleep(1000);
	}
	return (NULL);
}

void	create_death_monitor_thread(t_philo *philo)
{
	pthread_create(&(philo->death_thread), NULL, death_monitor_routine, philo);
	pthread_detach(philo->death_thread);
}
