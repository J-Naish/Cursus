#include "philo_bonus.h"

bool	should_simulation_continue(t_philo *philo)
{
	bool	b;

	sem_wait(philo->meta->sem_simulation);
	b = philo->meta->is_simulating;
	sem_post(philo->meta->sem_simulation);
	return (b);
}
