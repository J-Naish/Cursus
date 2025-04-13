#include "../../include/philo.h"

void	log_take_fork(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	pthread_mutex_lock(&(philo->meta->mutex_log));
	printf(WHITE"%d %lu has taken a fork\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
	pthread_mutex_unlock(&(philo->meta->mutex_log));
}

void	log_eat(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	pthread_mutex_lock(&(philo->meta->mutex_log));
	printf(YELLOW"%d %lu is eating\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
	pthread_mutex_unlock(&(philo->meta->mutex_log));
}

void	log_sleep(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	pthread_mutex_lock(&(philo->meta->mutex_log));
	printf(CYAN"%d %lu is sleeping\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
	pthread_mutex_unlock(&(philo->meta->mutex_log));
}

void	log_think(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	pthread_mutex_lock(&(philo->meta->mutex_log));
	printf(GREEN"%d %lu is thinking\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
	pthread_mutex_unlock(&(philo->meta->mutex_log));
}

void	log_die(t_philo *philo)
{
	pthread_mutex_lock(&(philo->meta->mutex_log));
	printf(RED"%d %lu died\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
	pthread_mutex_unlock(&(philo->meta->mutex_log));
}
