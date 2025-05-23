/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:03:11 by nash              #+#    #+#             */
/*   Updated: 2025/01/23 17:41:05 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_main(char s, int count, va_list args)
{
	int		prev_count;

	prev_count = count;
	if (s == '%')
		count += ft_putchar('%');
	else if (s == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		count += ft_putaddr(va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		count += ft_putint(va_arg(args, int));
	else if (s == 'u')
		count += ft_putuint(va_arg(args, unsigned int));
	else if (s == 'x')
		count += ft_puthex_lower(va_arg(args, unsigned int));
	else if (s == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned int));
	else
		count += ft_putchar(s);
	if (count < prev_count)
		return (-1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		prev_count;
	va_list	args;

	if (!s)
		return (-1);
	count = 0;
	va_start(args, s);
	while (*s)
	{
		prev_count = count;
		if (*s == '%')
		{
			s++;
			count = ft_printf_main(*s, count, args);
		}
		else
			count += ft_putchar(*s);
		if (count < prev_count)
			return (-1);
		s++;
	}
	va_end(args);
	return (count);
}
