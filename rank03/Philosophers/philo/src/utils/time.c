/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:40:53 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:40:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	elapsed = sec_diff * 1000 + usec_diff / 1000;
	return (elapsed);
}
