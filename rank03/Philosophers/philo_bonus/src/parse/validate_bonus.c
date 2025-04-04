/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:41:15 by nash              #+#    #+#             */
/*   Updated: 2025/04/05 07:41:15 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static bool	is_numstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_empty(const char *s)
{
	if (s[0] == '\0')
		return (true);
	else
		return (false);
}

static bool	has_zero_prefix(const char *s)
{
	if (s[0] == '0')
		return (true);
	else
		return (false);
}

static bool	is_within_sizet_limit(const char *s)
{
	int		i;
	size_t	sum;
	size_t	prev_sum;

	i = 0;
	sum = 0;
	prev_sum = 0;
	while (s[i])
	{
		sum = sum * 10 + (s[i] - '0');
		if (prev_sum > sum)
			return (false);
		prev_sum = sum;
		i++;
	}
	return (true);
}

bool	is_valid_arg(int argc, char **argv)
{
	int	i;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (is_empty(argv[i]))
			return (false);
		if (!is_numstr(argv[i]))
			return (false);
		if (has_zero_prefix(argv[i]))
			return (false);
		if (!is_within_sizet_limit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
