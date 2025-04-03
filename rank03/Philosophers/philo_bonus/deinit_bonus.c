#include "philo_bonus.h"

void	deinit_table(t_table *table)
{
	sem_close(table->meta->sem_forks);
	free(table->philos);
	free(table->meta);
	free(table);
}
