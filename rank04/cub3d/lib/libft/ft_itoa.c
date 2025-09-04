/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:11:19 by rnishi            #+#    #+#             */
/*   Updated: 2024/05/15 14:25:24 by rnishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_buffer(int n)
{
	int	buffer;

	buffer = 1;
	while (n >= 10 || n <= -10)
	{
		buffer += 1;
		n /= 10;
	}
	return (buffer);
}

char	*ft_itoa(int n)
{
	int		buffer;
	char	*result;
	int		i;
	int		is_minus;

	is_minus = (n < 0);
	buffer = ft_get_buffer(n);
	result = (char *)malloc((buffer + is_minus + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 1;
	while (i <= buffer)
	{
		if (n >= 0)
			result[buffer + is_minus - i] = '0' + (n % 10);
		else
			result[buffer + is_minus - i] = '0' - (n % 10);
		n /= 10;
		i++;
	}
	if (is_minus)
		result[0] = '-';
	result[buffer + is_minus] = '\0';
	return (result);
}
