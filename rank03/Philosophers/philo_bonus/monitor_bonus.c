#include "philo_bonus.h"

static bool	have_philo_eaten_enough(t_table table)
{
	size_t	i;

	i = 0;
	while (i < table.meta->config.num_philos)
	{
		if (table.philos[i].eating_count
			< table.meta->config.times_to_eat_to_exit)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_philo_starving(t_philo philo)
{
	if (philo.state == EATING)
		return (false);
	if ((size_t)get_elapsed_time(philo.last_meal_time)
		>= philo.meta->config.time_to_die)
		return (true);
	return (false);
}

void	monitor(t_table *table)
{
	size_t	i;

	while (table->meta->is_simulating)
	{
		if (have_philo_eaten_enough(*table))
		{
			sem_wait(table->meta->sem_simulation);
			table->meta->is_simulating = false;
			sem_post(table->meta->sem_simulation);
		}
		i = 0;
		while (i < table->meta->config.num_philos)
		{
			if (is_philo_starving(table->philos[i]))
			{
				sem_wait(table->meta->sem_simulation);
				table->meta->is_simulating = false;
				sem_post(table->meta->sem_simulation);
			}
			i++;
		}
	}
}
