/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:45:21 by nash              #+#    #+#             */
/*   Updated: 2024/05/22 22:30:39 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_bool.h"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putaddr(void *ptr);
int		ft_putint(int num);
int		ft_putuint(unsigned int num);
int		ft_puthexadecimal_lower(unsigned int num);
int		ft_puthexadecimal_upper(unsigned int num);

int		ft_puthexadecimal(unsigned long long num, t_bool is_upper);
t_bool	ft_is_printfable(char c);

#endif