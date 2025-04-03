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

static void	*subthread_routine(void *arg)
{
	t_philo	*philo;
	bool	has_eaten_enough;

	philo = (t_philo *)arg;
	has_eaten_enough = false;
	while (1)
	{
		if (is_starving(*philo))
		{
			log_died(*philo);
			exit(EXIT_SUCCESS);
		}
		if (!has_eaten_enough
			&& philo->eating_count > philo->meta->config.times_to_eat_to_exit)
		{
			has_eaten_enough = true;
			sem_post(philo->meta->sem_meals);
		}
		usleep(1000);
	}
	return (NULL);
}

void	create_subthread(t_philo *philo)
{
	pthread_create(&(philo->subthread), NULL, subthread_routine, philo);
	pthread_detach(philo->subthread);
}
