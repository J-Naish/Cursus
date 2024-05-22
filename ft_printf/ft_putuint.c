/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:43 by nash              #+#    #+#             */
/*   Updated: 2024/05/22 19:33:16 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int num)
{
	int	count;
	int	temp;

	count = 0;
	if (num < 10)
	{
		temp = ft_putchar('0' + num);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	else
	{
		temp = ft_putuint(num / 10);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_putuint(num % 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}
