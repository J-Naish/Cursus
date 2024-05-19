/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:36:50 by nash              #+#    #+#             */
/*   Updated: 2024/05/19 17:50:18 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_count_percent(const char *s)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			count += 1;
		i++;
	}
	return (count);
}

unsigned int	ft_percent_indicies_m(const char *s)
{
	unsigned int	*percent_idxs;
	unsigned int	percent_num;
	unsigned int	i;
	unsigned int	j;

	percent_num = ft_count_percent(s);
	percent_idxs = (unsigned int*)malloc(sizeof(unsigned int) * percent_num);
	if (!percent_idxs)
		return (NULL);
	i = 0;
	j = 0;
	while (i < percent_num && s[j])
	{
		if (s[j] == '%' && s[j + 1] != '%')
		{
			percent_idxs[i] = j;
			i++;
		}
		j++;
	}
	return (percent_idxs);
}
