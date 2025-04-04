#include "../philo_bonus.h"

static void	routine(t_table *table)
{
	size_t	finished_count;

	finished_count = 0;
	while (finished_count < table->meta->config.times_to_eat_to_exit)
	{
		sem_wait(table->meta->sem_meals);
		finished_count++;
	}
}

void	create_monitor_process(t_table *table)
{
	table->meta->monitor_pid = fork();
	if (table->meta->monitor_pid < 0)
	{
		destroy_processes(table, table->meta->config.num_philos);
	}
	else if (table->meta->monitor_pid == 0)
	{
		routine(table);
		printf(MAGENTA"All the philosophers have eaten enough times\n"RESET);
		exit(EXIT_FAILURE);
	}
}
