/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:06:37 by nash              #+#    #+#             */
/*   Updated: 2025/01/09 19:11:13 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_char_a(t_bool is_upper)
{
	if (is_upper)
		return ('A');
	else
		return ('a');
}

static int	ft_puthexadecimal_sub(unsigned long long num, t_bool is_upper)
{
	int		count;
	int		temp;

	count = 0;
	if (num % 16 < 10)
		temp = ft_putchar('0' + num % 16);
	else
		temp = ft_putchar(ft_get_char_a(is_upper) + (num % 16) - 10);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_puthexadecimal(unsigned long long num, t_bool is_upper)
{
	int		count;
	int		temp;

	count = 0;
	if (num < 16)
	{
		temp = ft_puthexadecimal_sub(num, is_upper);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	else
	{
		temp = ft_puthexadecimal(num / 16, is_upper);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_puthexadecimal(num % 16, is_upper);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

t_bool	ft_is_printf_conversion(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (TRUE);
	return (FALSE);
}
