/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:06:37 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 01:07:03 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadecimal(unsigned long long num)
{
	int	count;

	count = 0;
	if (num < 16)
	{
		if (num % 16 < 10)
			count += ft_putchar('0' + num % 16);
		else
			count += ft_putchar('a' + (num % 16) - 10);
	}
	else
	{
		count += ft_puthexadecimal(num / 16);
		count += ft_puthexadecimal(num % 16);
	}
	return (count);
}
