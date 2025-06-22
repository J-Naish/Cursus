/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:08 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:08 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	cmd_env(t_command *command, char ***envpp)
{
	int	i;

	if (command->args[1])
	{
		put_error(SHELL_NAME": no option nor argument is available\n");
		return ;
	}
	i = 0;
	while ((*envpp)[i])
	{
		ft_putendl_fd((*envpp)[i], STDOUT_FILENO);
		i++;
	}
}
