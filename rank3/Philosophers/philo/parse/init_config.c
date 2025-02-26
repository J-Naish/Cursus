/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:23:29 by nash              #+#    #+#             */
/*   Updated: 2025/02/27 08:39:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

t_config	init_config(int argc, char **argv)
{
	t_config	config;

	config.num_philos = convert_to_int(argv[1]);
	config.time_to_die = convert_to_int(argv[2]);
	config.time_to_eat = convert_to_int(argv[3]);
	config.time_to_sleep = convert_to_int(argv[4]);
	if (argc == 6)
		config.times_to_eat_to_exit = convert_to_int(argv[5]);
	else
		config.times_to_eat_to_exit = -1;
	return (config);
}
