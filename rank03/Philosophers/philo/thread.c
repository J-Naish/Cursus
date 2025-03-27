#include "philo.h"

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->monitor_mutex);
		if (!(*philo->simulation_running))
		{
			pthread_mutex_unlock(philo->monitor_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->monitor_mutex);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	create_philo_threads(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->config.num_philos)
	{
		pthread_create(&table->philos[i].tid, NULL,
			philo_routine, &table->philos[i]);
		i++;
	}
}

void	join_philo_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->config.num_philos)
	{
		pthread_join(table->philos[i].tid, NULL);
		i++;
	}
}
