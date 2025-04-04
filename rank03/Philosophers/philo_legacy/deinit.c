#include "philo.h"

void	deinit_table(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->monitor_mutex);
	free(table->philos);
	i = 0;
	while (i < table->config.num_philos)
	{
		pthread_mutex_destroy(&table->forks[i].mutex);
		i++;
	}
	free(table->forks);
	free(table);
}
