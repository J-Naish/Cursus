#include "philo.h"

static void	philo_take_fork(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(&philo->r_fork->mutex);
		if (!should_simulation_continue(*philo))
			return ;
		log_take_fork(*philo);
		pthread_mutex_lock(&philo->l_fork->mutex);
		log_take_fork(*philo);
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork->mutex);
		if (!should_simulation_continue(*philo))
			return ;
		log_take_fork(*philo);
		if (philo->config.num_philos == 1)
		{
			while (should_simulation_continue(*philo))
				usleep(1000);
			pthread_mutex_unlock(&philo->l_fork->mutex);
			return ;
		}
		pthread_mutex_lock(&philo->r_fork->mutex);
		log_take_fork(*philo);
	}
}

void	philo_eat(t_philo *philo)
{
	if (!should_simulation_continue(*philo))
		return ;
	philo_take_fork(philo);
	log_eat(*philo);
	philo->state = EATING;
	gettimeofday(&philo->last_meal_time, NULL);
	usleep(philo->config.time_to_eat * 1000);
	philo->eating_count += 1;
	if (philo->number % 2 == 0)
	{
		pthread_mutex_unlock(&philo->l_fork->mutex);
		pthread_mutex_unlock(&philo->r_fork->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->r_fork->mutex);
		pthread_mutex_unlock(&philo->l_fork->mutex);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (!should_simulation_continue(*philo))
		return ;
	philo->state = SLEEPING;
	log_sleep(*philo);
	split_sleep(philo->config.time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	if (!should_simulation_continue(*philo))
		return ;
	philo->state = THINKING;
	log_think(*philo);
}
