/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:40 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:41:40 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	deinit_table(t_table *table)
{
	unlink_sems(*(table->meta));
	sem_close(table->meta->sem_monitor);
	sem_close(table->meta->sem_log);
	sem_close(table->meta->sem_forks);
	sem_close(table->meta->sem_eating_count);
	sem_close(table->meta->sem_last_meal_time);
	free(table->philos);
	free(table->meta);
	free(table);
}
