/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:45:21 by nash              #+#    #+#             */
/*   Updated: 2024/05/20 01:07:13 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include "libft.h"

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putaddr(void *ptr);

int	ft_puthexadecimal(unsigned long long num);

#endif