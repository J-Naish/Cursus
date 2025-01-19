/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:19:55 by nash              #+#    #+#             */
/*   Updated: 2025/01/19 18:59:29 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;
	int	temp;

	count = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (*s)
	{
		temp = ft_putchar(*s);
		if (temp == -1)
			return (-1);
		count += temp;
		s++;
	}
	return (count);
}
