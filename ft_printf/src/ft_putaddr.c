/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:07:49 by nash              #+#    #+#             */
/*   Updated: 2025/01/11 23:55:07 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *ptr)
{
	unsigned long long	addr;
	int					count;
	int					temp;

	addr = (unsigned long long)ptr;
	count = 0;
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	count += temp;
	temp = ft_puthex(addr, FALSE);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
