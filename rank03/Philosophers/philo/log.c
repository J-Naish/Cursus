#include "philo.h"

void	log_take_fork(t_philo philo)
{
	struct timeval	now;

	if (!should_simulation_continue(philo))
		return ;
	gettimeofday(&now, NULL);
	printf("%d %d has taken a fork\n",
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_eat(t_philo philo)
{
	if (!should_simulation_continue(philo))
		return ;
	printf(YELLOW "%d %d is eating\n" RESET,
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_sleep(t_philo philo)
{
	if (!should_simulation_continue(philo))
		return ;
	printf(CYAN "%d %d is sleeping\n" RESET,
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_think(t_philo philo)
{
	if (!should_simulation_continue(philo))
		return ;
	printf(GREEN "%d %d is thinking\n" RESET,
		get_elapsed_time(philo.start_time), philo.number);
}

void	log_died(t_philo philo)
{
	printf(RED "%d %d died\n" RESET,
		get_elapsed_time(philo.start_time), philo.number);
}
