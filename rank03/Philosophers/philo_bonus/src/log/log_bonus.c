#include "../philo_bonus.h"

void	log_take_fork(t_philo philo)
{
	log_action(philo, NULL, "has taken a fork\n");
}

void	log_eat(t_philo philo)
{
	log_action(philo, YELLOW, "is eating\n");
}

void	log_sleep(t_philo philo)
{
	log_action(philo, CYAN, "is sleeping\n");
}

void	log_think(t_philo philo)
{
	log_action(philo, GREEN, "is thinking\n");
}

void	log_died(t_philo philo)
{
	log_action(philo, RED, "died\n");
}
