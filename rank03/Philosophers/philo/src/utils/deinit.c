#include "../../include/philo.h"

static void	destroy_mutexes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_mutex_destroy(&(table->forks[i].mutex));
		pthread_mutex_destroy(&(table->philos[i].mutex_last_meal_time));
		pthread_mutex_destroy(&(table->philos[i].mutex_eating_count));
		i++;
	}
	pthread_mutex_destroy(&(table->meta->monitor->mutex));
	pthread_mutex_destroy(&(table->meta->mutex_log));
}

void	deinit_table(t_table *table)
{
	destroy_mutexes(table);
	free(table->philos);
	free(table->forks);
	free(table->meta->monitor);
	free(table->meta);
	free(table);
}
