#include "../philo_bonus.h"

void	deinit_table(t_table *table)
{
	unlink_sems(*(table->meta));
	sem_close(table->meta->sem_monitor);
	sem_close(table->meta->sem_log);
	sem_close(table->meta->sem_forks);
	sem_close(table->meta->sem_eating_count);
	free(table->philos);
	free(table->meta);
	free(table);
}
