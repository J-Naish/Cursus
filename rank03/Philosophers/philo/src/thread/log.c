#include "../philo.h"

void	log_take_fork(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	printf(WHITE"%d %lu has taken a fork\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
}

void	log_eat(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	printf(YELLOW"%d %lu is eating\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
}

void	log_sleep(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	printf(CYAN"%d %lu is sleeping\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
}

void	log_think(t_philo *philo)
{
	if (should_simulation_stop(philo->meta->monitor))
		return ;
	printf(GREEN"%d %lu is thinking\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
}

void	log_die(t_philo *philo)
{
	printf(RED"%d %lu died\n"RESET,
		get_elapsed_time(philo->meta->start_time), philo->number);
}
