/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_sems_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:45 by nash              #+#    #+#             */
/*   Updated: 2025/04/09 00:48:14 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

void	unlink_sems(t_meta meta)
{
	sem_unlink(meta.sem_name_forks);
	sem_unlink(meta.sem_name_log);
	sem_unlink(meta.sem_name_monitor);
	sem_unlink(meta.sem_name_eating_count);
	sem_unlink(meta.sem_name_last_meal_time);
}
