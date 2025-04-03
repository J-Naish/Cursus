#include "../philo_bonus.h"

void	deinit_table(t_table *table)
{
	sem_close(table->meta->sem_forks);
	sem_close(table->meta->sem_log);
	free(table->philos);
	free(table->meta);
	free(table);
}
