/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_processes_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:23 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 00:47:53 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

void	destroy_processes(t_table *table, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		kill(table->philos[j].pid, SIGTERM);
		j++;
	}
}
