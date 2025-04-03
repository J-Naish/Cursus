#include "../philo_bonus.h"

void	log_take_fork(t_philo philo)
{
	printf(WHITE"%d %zu has taken a fork\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
}

void	log_eat(t_philo philo)
{
	printf(YELLOW"%d %zu is eating\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
}

void	log_sleep(t_philo philo)
{
	printf(CYAN"%d %zu is sleeping\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
}

void	log_think(t_philo philo)
{
	printf(GREEN"%d %zu is thinking\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
}

void	log_died(t_philo philo)
{
	printf(RED"%d %zu died\n"RESET,
		get_elapsed_time(philo.meta->start_time), philo.number);
}
