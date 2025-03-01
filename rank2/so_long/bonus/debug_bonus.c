/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:36:06 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 23:45:23 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_movements(int n)
{
	ft_putstr_fd("Number of movements: ", STDOUT_FILENO);
	ft_putnbr_fd(n, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
