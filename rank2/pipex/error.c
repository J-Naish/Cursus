/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:19:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 21:35:01 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("");
	exit(errno);
}

void	malloc_failure_exit(void)
{
	ft_putstr_fd("memory allocation failed\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_putstr_fd("invalid args\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
