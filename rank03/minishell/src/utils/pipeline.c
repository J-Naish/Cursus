/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:54:01 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:54:01 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	get_command_count(t_pipeline *pipeline)
{
	int	count;

	count = 0;
	while (pipeline->commands[count])
		count++;
	return (count);
}
