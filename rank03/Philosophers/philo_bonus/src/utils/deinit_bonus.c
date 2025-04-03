#include "../philo_bonus.h"

void	deinit_table(t_table *table)
{
	sem_unlink(table->meta->sem_name_death);
	sem_close(table->meta->sem_death);
	sem_unlink(table->meta->sem_name_meals);
	sem_close(table->meta->sem_meals);
	sem_unlink(table->meta->sem_name_log);
	sem_close(table->meta->sem_log);
	sem_unlink(table->meta->sem_name_forks);
	sem_close(table->meta->sem_forks);
	free(table->philos);
	free(table->meta);
	free(table);
}
