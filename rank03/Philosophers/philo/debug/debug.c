/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:33:09 by nash              #+#    #+#             */
/*   Updated: 2025/03/10 01:31:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_config(t_config config)
{
	printf("number_of_philosophers:                    %d\n",
		config.num_philos);
	printf("time_to_die:                               %d\n",
		config.time_to_die);
	printf("time_to_eat:                               %d\n",
		config.time_to_eat);
	printf("time_to_sleep:                             %d\n",
		config.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		config.times_to_eat_to_exit);
}

void	print_philos(t_table table)
{
	int	i;

	i = 0;
	while (i < table.config.num_philos)
	{
		printf("Philo %d is on the table.\n", table.philos[i].number);
		i++;
	}
}
