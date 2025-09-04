/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:59:09 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:19:42 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip_space(const char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		{
			*i += 1;
			continue ;
		}
		else
		{
			break ;
		}
	}
}

static int	ft_detect_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

static int	ft_atoi_main(const char *str, int i, int sign, long long result)
{
	long long	prev_result;

	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			prev_result = result;
			result = result * 10 + (str[i] - '0');
			if (result < prev_result)
			{
				if (sign == 1)
					return (-1);
				else
					return (0);
			}
		}
		else
			break ;
		i++;
	}
	return ((int)result);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	ft_skip_space(str, &i);
	sign = ft_detect_sign(str, &i);
	result = ft_atoi_main(str, i, sign, result);
	return ((int)(result * sign));
}
