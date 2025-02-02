/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:40:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/02 19:41:18 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(void)
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

void	insert_after(t_node *node, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->prev->next = new;
}

void	append(t_list *list, int value)
{
	insert_after(list->sentinel->prev, value);
}

void	remove(t_node *node)
{
	if (!node)
		return ;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

void	pop(t_list *list)
{
	remove(list->sentinel->prev);
}
