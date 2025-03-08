/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:19:01 by nash              #+#    #+#             */
/*   Updated: 2025/03/08 21:00:35 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("");
	exit(errno);
}

void	command_not_found(void)
{
	ft_putstr_fd("command not found\n", STDERR_FILENO);
	exit(127);
}

void	not_enough_arguments_error(void)
{
	ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
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
