#include "philo_bonus.h"

void	create_processes(t_table *table, void (*routine)(t_philo *))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < table->meta->config.num_philos)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid < 0)
		{
			j = 0;
			while (j < i)
			{
				kill(table->philos[j].pid, SIGTERM);
				j++;
			}
			deinit_table(table);
			exit(EXIT_FAILURE);
		}
		else if (table->philos[i].pid == 0)
		{
			routine(&(table->philos[i]));
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
