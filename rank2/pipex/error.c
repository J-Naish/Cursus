/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:19:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/17 03:28:53 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	puterrno(void)
{
	ft_putstr_fd(STDERR_FILENO, strerror(errno));
	ft_putstr_fd(STDERR_FILENO, "\n");
}

void	error_exit(void)
{
	puterrno();
	exit(EXIT_FAILURE);
}
