/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:39:59 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 06:46:14 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min_node(t_list *list)
{
	t_node	*min;
	t_node	*current;

	if (!list || list->sentinel->next == list->sentinel)
		return (NULL);
	min = list->sentinel->next;
	current = min->next;
	while (current != list->sentinel)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
