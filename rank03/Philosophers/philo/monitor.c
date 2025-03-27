#include "philo.h"

static void	update_bool(bool *simulation_running, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*simulation_running = false;
	pthread_mutex_unlock(mutex);
}

static void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (table->simulation_running)
	{
		i = 0;
		if (have_eaten_enough(*table))
		{
			update_bool(&(table->simulation_running), &(table->monitor_mutex));
			return (NULL);
		}
		while (i < table->config.num_philos)
		{
			if (is_philo_starving(table->philos[i]))
			{
				log_died(table->philos[i]);
				update_bool(&(table->simulation_running),
					&(table->monitor_mutex));
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
