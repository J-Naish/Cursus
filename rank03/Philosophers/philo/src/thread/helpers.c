#include "../philo.h"

bool	get_is_simulating(t_monitor *monitor)
{
	bool	b;

	pthread_mutex_lock(&(monitor->mutex));
	b = monitor->is_simulating;
	pthread_mutex_unlock(&(monitor->mutex));
	return (b);
}

void	split_sleep(size_t duration, t_monitor *monitor)
{
	struct timeval	start;

	start = get_current_time();
	while ((size_t)get_elapsed_time(start) <= duration)
	{
		if (!get_is_simulating(monitor))
			return ;
		usleep(1000);
	}
}
