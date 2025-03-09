/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:02:29 by nash              #+#    #+#             */
/*   Updated: 2025/03/10 01:05:50 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

static bool	has_zero_prefix(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 1 && s[0] == '0')
		return (true);
	else
		return (false);
}

static bool	is_empty(const char *s)
{
	if (s[0] == '\0')
		return (true);
	else
		return (false);
}

bool	is_valid_arg(int argc, char **argv)
{
	int	i;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (is_empty(argv[i]) || !is_numstr(argv[i]))
			return (false);
		if (has_zero_prefix(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
