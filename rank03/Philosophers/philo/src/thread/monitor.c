#include "../../include/philo.h"

bool	is_one_of_philos_starving(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_mutex_lock(&(table->philos[i].mutex_last_meal_time));
		if ((size_t)get_elapsed_time(table->philos[i].last_meal_time)
			>= table->meta->config.time_to_die)
		{
			pthread_mutex_unlock(&(table->philos[i].mutex_last_meal_time));
			log_die(&(table->philos[i]));
			return (true);
		}
		pthread_mutex_unlock(&(table->philos[i].mutex_last_meal_time));
		i++;
	}
	return (false);
}

bool	have_all_philos_eaten_enough(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_mutex_lock(&(table->philos[i].mutex_eating_count));
		if (table->philos[i].eating_count
			< table->meta->config.times_to_eat_to_exit)
		{
			pthread_mutex_unlock(&(table->philos[i].mutex_eating_count));
			return (false);
		}
		pthread_mutex_unlock(&(table->philos[i].mutex_eating_count));
		i++;
	}
	return (true);
}
