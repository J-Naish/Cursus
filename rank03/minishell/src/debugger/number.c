/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:34 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:34 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debugger.h"

void	print_number(int n)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putnbr_fd(n, STDOUT_FILENO);
	ft_putstr_fd(RESET, STDOUT_FILENO);
}
