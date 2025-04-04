#include "../philo_bonus.h"

void	unlink_sems(t_meta meta)
{
	sem_unlink(meta.sem_name_forks);
	sem_unlink(meta.sem_name_log);
	sem_unlink(meta.sem_name_monitor);
	sem_unlink(meta.sem_name_eating_count);
	sem_unlink(meta.sem_name_last_meal_time);
}
