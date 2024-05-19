/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:03:11 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 02:54:21 by nash             ###   ########.fr       */
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
			if (*s == '%')
				count += ft_putchar('%');
			else if (*s == 'c')
				count += ft_putchar(va_arg(args, char));
			else if (*s == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*s == 'p')
				count += ft_putaddr(va_arg(args, void *));
			else if (*s == 'd' || *s == 'i')
				count += ft_putint(va_arg(args, int));
			else if (*s == 'u')
				count += ft_putuint(va_arg(args, unsigned int));
			else if (*s == 'x')
				count += ft_puthexadecimal_lower(va_arg(args, unsigned int));
			else if (*s == 'X')
				count += ft_puthexadecimal_upper(va_arg(args, unsigned int));
			else
				return (count);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
