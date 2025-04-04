#include "../philo.h"

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	(void)table;
	while (1)
	{
	}
	return (NULL);
}

void	create_threads(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_create(&(table->philos[i].tid), NULL,
			routine, &(table->philos[i]));
		i++;
	}
	pthread_create(&(table->meta->monitor->tid), monitor_routine, NULL, table);
	pthread_join(table->meta->monitor->tid, NULL);
	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_join(table->philos[i].tid, NULL);
		i++;
	}
}
