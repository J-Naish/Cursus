#include "../philo.h"

static bool	is_starving(t_philo *philo)
{
	bool	b;

	pthread_mutex_lock(&(philo->mutex));
	b = get_elapsed_time(philo->last_meal_time)
		>= philo->meta->config.time_to_die;
	pthread_mutex_unlock(&(philo->mutex));
	return (b);
}

void	monitor(t_table *table)
{
}
