/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:42 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 19:15:58 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

struct timeval	get_current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now);
}

int	get_elapsed_time(struct timeval start_time)
{
	struct timeval	now;
	int				sec_diff;
	int				usec_diff;
	int				elapsed;

	now = get_current_time();
	sec_diff = now.tv_sec - start_time.tv_sec;
	usec_diff = now.tv_usec - start_time.tv_usec;
	if (usec_diff < 0)
	{
		sec_diff--;
		usec_diff += 1000000;
	}
	elapsed = sec_diff * 1000 + usec_diff / 1000;
	return (elapsed);
}
