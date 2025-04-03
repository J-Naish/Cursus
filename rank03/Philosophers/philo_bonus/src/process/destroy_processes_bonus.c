#include "../philo_bonus.h"

void	destroy_processes(t_table *table, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		kill(table->philos[j].pid, SIGTERM);
		j++;
	}
}
