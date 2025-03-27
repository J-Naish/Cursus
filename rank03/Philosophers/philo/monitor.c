#include "philo.h"

static void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (table->simulation_running)
	{
		i = 0;
		while (i < table->config.num_philos)
		{
			if (is_philo_starving(table->philos[i]))
			{
				log_died(table->philos[i]);
				pthread_mutex_lock(&table->monitor_mutex);
				table->simulation_running = false;
				pthread_mutex_unlock(&table->monitor_mutex);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	create_monitor_thread(t_table *table)
{
	pthread_create(&(*table).monitor_tid, NULL, monitor_routine, table);
}

void	join_monitor_thread(t_table *table)
{
	pthread_join((*table).monitor_tid, NULL);
}
