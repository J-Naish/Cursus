/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:45:21 by nash              #+#    #+#             */
/*   Updated: 2025/01/19 19:38:08 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putaddr(void *ptr);
int		ft_putint(int num);
int		ft_putuint(unsigned int num);
int		ft_puthex_lower(unsigned int num);
int		ft_puthex_upper(unsigned int num);

int		ft_puthex(unsigned long long num, bool is_upper);

int		ft_printf(const char *s, ...);

#endif