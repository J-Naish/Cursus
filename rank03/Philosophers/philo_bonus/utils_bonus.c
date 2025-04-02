#include "philo_bonus.h"

bool	should_simulation_continue(t_philo *philo)
{
	bool	b;

	sem_wait(philo->meta->sem_simulation);
	b = philo->meta->is_simulating;
	sem_post(philo->meta->sem_simulation);
	return (b);
}

void	split_sleep(int duration, t_philo *philo)
{
	struct timeval	start;

	start = get_current_time();
	while (get_elapsed_time(start) < duration)
	{
		sem_wait(philo->meta->sem_simulation);
		if (!philo->meta->is_simulating)
		{
			sem_post(philo->meta->sem_simulation);
			return ;
		}
		sem_post(philo->meta->sem_simulation);
		usleep(1000);
	}
}
