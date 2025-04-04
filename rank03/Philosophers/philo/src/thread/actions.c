#include "../philo.h"

static void	philo_take_fork(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(&(philo->l_fork->mutex));
		log_take_fork(*philo);
		pthread_mutex_lock(&(philo->r_fork->mutex));
		log_take_fork(*philo);
	}
	else
	{
		pthread_mutex_lock(&(philo->r_fork->mutex));
		log_take_fork(*philo);
		pthread_mutex_lock(&(philo->l_fork->mutex));
		log_take_fork(*philo);
	}
}

void	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	log_eat(*philo);
	philo->state = EATING;
	pthread_mutex_lock(&(philo->mutex_last_meal_time));
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&(philo->mutex_last_meal_time));
	usleep(philo->meta->config.time_to_eat * 1000);
	philo->eating_count += 1;
	if (philo->number % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->r_fork->mutex));
		pthread_mutex_unlock(&(philo->l_fork->mutex));
	}
	else
	{
		pthread_mutex_unlock(&(philo->l_fork->mutex));
		pthread_mutex_unlock(&(philo->r_fork->mutex));
	}
}

void	philo_sleep(t_philo *philo)
{
	log_sleep(*philo);
	philo->state = SLEEPING;
	usleep(philo->meta->config.time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	log_think(*philo);
	philo->state = THINKING;
}
