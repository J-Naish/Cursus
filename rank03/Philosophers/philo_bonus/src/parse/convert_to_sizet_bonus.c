/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_sizet_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:10 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:41:10 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

size_t	convert_to_sizet(const char *s)
{
	size_t	result;
	int		i;

	result = 0;
	i = 0;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}
