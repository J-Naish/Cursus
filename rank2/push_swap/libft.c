/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:11:22 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:28:05 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	write(STDOUT_FILENO, s, len);
}
