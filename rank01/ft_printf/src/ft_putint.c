/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:14:34 by nash              #+#    #+#             */
/*   Updated: 2024/05/22 19:31:52 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putll_sub(long long *num)
{
	int	count;
	int	temp;

	count = 0;
	if (*num < 0)
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		count += temp;
		*num *= -1;
	}
	return (count);
}

static int	ft_putll(long long num)
{
	int	count;
	int	temp;

	count = ft_putll_sub(&num);
	if (count == -1)
		return (-1);
	if (num < 10)
	{
		temp = ft_putchar('0' + num);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	else
	{
		temp = ft_putll(num / 10);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_putll(num % 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

static int	ft_putint_sub(int *num)
{
	int	count;
	int	temp;

	count = 0;
	if (*num == INT_MIN)
		return (ft_putll((long long)*num));
	if (*num < 0)
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		count += temp;
		*num *= -1;
	}
	if (*num < 10)
	{
		temp = ft_putchar('0' + *num);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

int	ft_putint(int num)
{
	int	count;
	int	temp;

	count = 0;
	temp = ft_putint_sub(&num);
	if (temp == -1)
		return (-1);
	count += temp;
	if (num >= 10)
	{
		temp = ft_putint(num / 10);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_putint(num % 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}
