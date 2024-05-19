/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:43 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 01:53:57 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int num)
{
	int	count;

	count = 0;
	if (num < 10)
	{
		count += ft_putchar('0' + num);
	}
	else
	{
		count += ft_putuint(num / 10);
		count += ft_putuint(num % 10);
	}
	return (count);
}
