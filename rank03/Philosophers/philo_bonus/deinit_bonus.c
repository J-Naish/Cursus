#include "philo_bonus.h"

void	deinit_table(t_table *table)
{
	sem_unlink(table->sem_name);
	sem_close(table->sem_forks);
	free(table->philos);
	free(table);
}
