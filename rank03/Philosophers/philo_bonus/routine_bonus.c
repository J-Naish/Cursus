#include "philo_bonus.h"

void	routine(t_philo *philo)
{
	usleep(100);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
