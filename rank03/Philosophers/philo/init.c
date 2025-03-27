/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:23:29 by nash              #+#    #+#             */
/*   Updated: 2025/03/27 18:26:08 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	convert_to_int(const char *s)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}

static t_config	init_config(int argc, char **argv)
{
	t_config	config;

	config.num_philos = convert_to_int(argv[1]);
	config.time_to_die = convert_to_int(argv[2]);
	config.time_to_eat = convert_to_int(argv[3]);
	config.time_to_sleep = convert_to_int(argv[4]);
	if (argc == 6)
		config.times_to_eat_to_exit = convert_to_int(argv[5]);
	else
		config.times_to_eat_to_exit = INT_MAX;
	return (config);
}

static t_philo	init_philo(int number, t_table *table)
{
	t_philo	philo;

	philo.number = number;
	philo.state = THINKING;
	philo.eating_count = 0;
	gettimeofday(&philo.last_meal_time, NULL);
	philo.start_time = table->start_time;
	philo.config = table->config;
	philo.l_fork = &table->forks[number - 1];
	if (number == 1)
		philo.r_fork = &table->forks[table->config.num_philos - 1];
	else
		philo.r_fork = &table->forks[number - 2];
	philo.simulation_running = &table->simulation_running;
	philo.monitor_mutex = &table->monitor_mutex;
	return (philo);
}

static t_fork	init_fork(int number)
{
	t_fork	fork;

	fork.number = number;
	pthread_mutex_init(&fork.mutex, NULL);
	return (fork);
}

t_table	init_table(int argc, char **argv)
{
	t_table		table;
	int			i;

	table.config = init_config(argc, argv);
	gettimeofday(&table.start_time, NULL);
	table.simulation_running = true;
	pthread_mutex_init(&table.monitor_mutex, NULL);
	table.philos = malloc(sizeof(t_philo) * table.config.num_philos);
	if (!table.philos)
		exit(EXIT_FAILURE);
	table.forks = malloc(sizeof(t_fork) * table.config.num_philos);
	if (!table.forks)
	{
		free(table.philos);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < table.config.num_philos)
	{
		table.philos[i] = init_philo(i + 1, &table);
		table.forks[i] = init_fork(i + 1);
		i++;
	}
	return (table);
}
