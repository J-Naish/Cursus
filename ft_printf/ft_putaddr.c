/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:07:49 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 01:13:44 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	addr = (unsigned long long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexadecimal(addr);
	return (count);
}
