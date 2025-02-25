/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:19:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/25 19:11:52 by nash             ###   ########.fr       */
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
	write(STDERR_FILENO, "memory allocation failed\n", 25);
	exit(EXIT_FAILURE);
}
