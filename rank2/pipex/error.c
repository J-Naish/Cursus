/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:19:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/23 07:55:56 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	perror("");
	exit(EXIT_FAILURE);
}

void	malloc_failure_exit(void)
{
	perror("memory allocation failed");
	exit(EXIT_FAILURE);
}
