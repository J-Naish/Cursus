#include "../philo_bonus.h"

void	log_take_fork(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(WHITE"%d %zu has taken a fork\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_eat(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(YELLOW"%d %zu is eating\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_sleep(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(CYAN"%d %zu is sleeping\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_think(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(GREEN"%d %zu is thinking\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}

void	log_died(t_philo philo)
{
	sem_wait(philo.meta->sem_log);
	printf(RED"%d %zu died\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
	sem_post(philo.meta->sem_log);
}
