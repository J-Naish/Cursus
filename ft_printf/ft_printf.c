/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:03:11 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 00:42:08 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (s == '%')
			{
				count += ft_putchar('%');
				s++;
				continue ;
			}
			else if (s == 'c')
			{
				count += ft_putchar(va_arg(args, char));
				s++;
			}
			else if (s == 's')
			{
				count += ft_putstr(va_arg(args, char *));
				s++;
			}
			else if (s == 'p')
			{
				count += ft_putaddr(va_arg(args, void *));
				s++;
			}
		}
		else
			count += ft_putchar(*s);
		s++;
	}
}
