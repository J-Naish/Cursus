#include "philo_bonus.h"

static void	destroy_processes(t_table *table, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		kill(table->philos[j].pid, SIGTERM);
		j++;
	}
}

void	create_philo_processes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid < 0)
		{
			destroy_processes(table, i);
			return ;
		}
		else if (table->philos[i].pid == 0)
		{
			routine(&(table->philos[i]));
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	wait_philo_processes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		waitpid(table->philos[i].pid, NULL, 0);
		i++;
	}
}
