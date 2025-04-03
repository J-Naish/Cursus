#include "philo_bonus.h"

void	create_monitor_process(t_table *table)
{
	size_t	i;

	table->monitor.pid = fork();
	if (table->monitor.pid < 0)
	{
		i = 0;
		while (i < table->meta->config.num_philos)
		{
			kill(table->philos[i].pid, SIGTERM);
			i++;
		}
		return ;
	}
	else if (table->monitor.pid == 0)
	{
		monitor_routine(table);
	}
	else
	{
		waitpid(table->monitor.pid, NULL, 0);
	}
}

void	wait_monitor_process(t_table *table)
{
	waitpid(table->monitor.pid, NULL, 0);
}
