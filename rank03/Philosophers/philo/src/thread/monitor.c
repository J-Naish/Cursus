#include "../philo.h"

static bool	is_starving(t_philo *philo)
{
	bool	b;

	pthread_mutex_lock(&(philo->mutex_last_meal_time));
	b = get_elapsed_time(philo->last_meal_time)
		>= philo->meta->config.time_to_die;
	pthread_mutex_unlock(&(philo->mutex_last_meal_time));
	return (b);
}

static bool	have_all_philo_eaten_enough(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		i++;
	}
}

void	monitor(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		if (is_starving(&(table->philos[i])))
		{
			pthread_mutex_lock(&(table->meta->monitor->mutex));
			table->meta->monitor->is_simulating = false;
			pthread_mutex_unlock(&(table->meta->monitor->mutex));
			return ;
		}
		i++;
	}
}
