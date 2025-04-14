#include "../../include/philo.h"

static void	philo_take_fork(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	pthread_mutex_lock(&(philo->r_fork->mutex));
	log_take_fork(philo);
	if (philo->meta->config.num_philos == 1)
	{
		while (!should_simulation_stop(philo->meta->monitor))
			usleep(1000);
		pthread_mutex_unlock(&(philo->r_fork->mutex));
		return ;
	}
	pthread_mutex_lock(&(philo->l_fork->mutex));
	log_take_fork(philo);
}

void	philo_eat(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	philo_take_fork(philo);
	if (philo->meta->config.num_philos == 1)
		return ;
	log_eat(philo);
	pthread_mutex_lock(&(philo->mutex_last_meal_time));
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&(philo->mutex_last_meal_time));
	split_sleep(philo->meta->config.time_to_eat, philo->meta->monitor);
	pthread_mutex_lock(&(philo->mutex_eating_count));
	philo->eating_count += 1;
	pthread_mutex_unlock(&(philo->mutex_eating_count));
	pthread_mutex_unlock(&(philo->r_fork->mutex));
	pthread_mutex_unlock(&(philo->l_fork->mutex));
}

void	philo_sleep(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	log_sleep(philo);
	split_sleep(philo->meta->config.time_to_sleep, philo->meta->monitor);
}

void	philo_think(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	log_think(philo);
}
