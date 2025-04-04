/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:25 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:40:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_monitor	*init_monitor(void)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	monitor->is_simulating = true;
	pthread_mutex_init(&(monitor->mutex), NULL);
	return (monitor);
}

static t_meta	*init_meta(int argc, char **argv)
{
	t_meta		*meta;
	t_config	config;

	config.num_philos = convert_to_sizet(argv[1]);
	config.time_to_die = convert_to_sizet(argv[2]);
	config.time_to_eat = convert_to_sizet(argv[3]);
	config.time_to_sleep = convert_to_sizet(argv[4]);
	if (argc == 6)
		config.times_to_eat_to_exit = convert_to_sizet(argv[5]);
	else
		config.times_to_eat_to_exit = SIZE_MAX;
	meta = (t_meta *)malloc(sizeof(t_meta));
	if (!meta)
		return (NULL);
	meta->config = config;
	meta->start_time = get_current_time();
	meta->monitor = init_monitor();
	if (!meta->monitor)
		return (free(meta), NULL);
	return (meta);
}

static t_fork	*init_forks(t_meta *meta)
{
	t_fork	*forks;
	size_t	i;

	forks = (t_fork *)malloc(sizeof(t_fork) * meta->config.num_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < meta->config.num_philos)
	{
		forks[i].number = i + 1;
		pthread_mutex_init(&(forks[i].mutex), NULL);
		i++;
	}
	return (forks);
}

static t_philo	*init_philos(t_meta *meta, t_fork *forks)
{
	t_philo	*philos;
	size_t	i;

	philos = (t_philo *)malloc(sizeof(t_philo) * meta->config.num_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < meta->config.num_philos)
	{
		philos[i].number = i + 1;
		philos[i].eating_count = 0;
		philos[i].last_meal_time = get_current_time();
		philos[i].l_fork = &(forks[i]);
		if (i == 0)
			philos[i].r_fork = &(forks[meta->config.num_philos - 1]);
		else
			philos[i].r_fork = &(forks[i - 1]);
		philos[i].meta = meta;
		pthread_mutex_init(&(philos[i].mutex_last_meal_time), NULL);
		pthread_mutex_init(&(philos[i].mutex_eating_count), NULL);
		i++;
	}
	return (philos);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->meta = init_meta(argc, argv);
	if (!table->meta)
		return (free(table), NULL);
	table->forks = init_forks(table->meta);
	if (!table->forks)
		return (free(table->meta), free(table), NULL);
	table->philos = init_philos(table->meta, table->forks);
	if (!table->philos)
		return (free(table->forks), free(table->meta), free(table), NULL);
	return (table);
}
