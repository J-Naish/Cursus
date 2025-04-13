#include "../../include/philo.h"

static void	*routine(void *arg)
{
	t_philo	*philo;
	size_t	time_to_eat;

	philo = (t_philo *)arg;
	time_to_eat = philo->meta->config.time_to_eat;
	if (philo->meta->config.num_philos % 2 == 1)
	{
		if (philo->number % 2 == 1)
			split_sleep((time_to_eat * (philo->number / 2))
				/ (philo->meta->config.num_philos / 2), philo->meta->monitor);
		else
			split_sleep(time_to_eat
				+ ((time_to_eat / (philo->meta->config.num_philos / 2))),
				philo->meta->monitor);
	}
	while (1)
	{
		if (should_simulation_stop(philo->meta->monitor))
			return (NULL);
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
		if (is_one_of_philos_starving(table))
		{
			pthread_mutex_lock(&(table->meta->monitor->mutex));
			table->meta->monitor->is_simulating = false;
			pthread_mutex_unlock(&(table->meta->monitor->mutex));
			return (NULL);
		}
		if (have_all_philos_eaten_enough(table))
		{
			pthread_mutex_lock(&(table->meta->monitor->mutex));
			table->meta->monitor->is_simulating = false;
			pthread_mutex_unlock(&(table->meta->monitor->mutex));
			return (NULL);
		}
		usleep(1000);
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
		usleep(1);
		i++;
	}
	pthread_create(&(table->meta->monitor->tid), NULL, monitor_routine, table);
	pthread_join(table->meta->monitor->tid, NULL);
	i = 0;
	while (i < table->meta->config.num_philos)
	{
		pthread_join(table->philos[i].tid, NULL);
		i++;
	}
}
