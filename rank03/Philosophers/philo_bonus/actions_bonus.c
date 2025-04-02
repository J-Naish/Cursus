#include "philo_bonus.h"

static void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->meta->sem_forks);
	log_take_fork(*philo);
	sem_wait(philo->meta->sem_forks);
	log_take_fork(*philo);
}

void	philo_eat(t_philo *philo)
{
	philo_take_fork(philo);
	philo->state = EATING;
	log_eat(*philo);
	split_sleep(philo->meta->config.time_to_eat, philo);
	philo->last_meal_time = get_current_time();
	philo->eating_count += 1;
	sem_post(philo->meta->sem_forks);
	sem_post(philo->meta->sem_forks);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	log_sleep(*philo);
	split_sleep(philo->meta->config.time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	log_think(*philo);
}
