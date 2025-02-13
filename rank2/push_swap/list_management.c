/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:18:26 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 05:02:06 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->sentinel = (t_node *)malloc(sizeof(t_node));
	if (!list->sentinel)
		return (free(list), NULL);
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	return (list);
}

void	free_list(t_list *list)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return ;
	current = list->sentinel->next;
	while (current != list->sentinel)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(list->sentinel);
	free(list);
}

bool	is_empty(t_list *list)
{
	if (list->sentinel->next == list->sentinel)
		return (true);
	else
		return (false);
}

bool	is_singleton(t_list *list)
{
	if (list->sentinel->next->next == list->sentinel)
		return (true);
	else
		return (false);
}
