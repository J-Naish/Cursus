/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:14:34 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 01:34:26 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putll(long long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
	{
		count += ft_putchar('0' + num);
	}
	else
	{
		count += ft_putll(num / 10);
		count += ft_putll(num % 10);
	}
	return (count);
}

int	ft_putint(int num)
{
	int	count;

	count = 0;
	if (num == INT_MIN)
	{
		count += ft_putll(num);
		return (count);
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
	{
		count += ft_putchar('0' + num);
	}
	else
	{
		count += ft_putint(num / 10);
		count += ft_putint(num % 10);
	}
	return (count);
}

