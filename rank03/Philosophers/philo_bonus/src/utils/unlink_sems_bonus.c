#include "../philo_bonus.h"

void	unlink_sems(t_meta *meta)
{
	sem_unlink(meta->sem_name_forks);
	sem_unlink(meta->sem_name_log);
	sem_unlink(meta->sem_name_meals);
	sem_unlink(meta->sem_name_death);
}
