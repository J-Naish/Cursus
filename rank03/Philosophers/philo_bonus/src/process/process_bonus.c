#include "../philo_bonus.h"

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

static void	routine(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	create_processes(t_table *table)
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
			create_subthread(&(table->philos[i]));
			routine(&(table->philos[i]));
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	waitpid(-1, NULL, 0);
	destroy_processes(table, table->meta->config.num_philos);
	while (waitpid(-1, NULL, 0) > 0)
		;
}
