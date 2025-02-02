/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:05:24 by nash              #+#    #+#             */
/*   Updated: 2025/02/01 21:33:24 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *head)
{
	struct t_node	*first;
	struct t_node	*second;

	if (!head || !head->next)
		return (head);
	first = head;
	second = head->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
}

void	sa(t_node *a_head)
{
	swap(a_head);
	write(STDOUT_FILENO, "sa", 2);
}

void	sb(t_node *b_head)
{
	swap(b_head);
	write(STDOUT_FILENO, "sb", 2);
}

void	ss(t_node *a_head, t_node *b_head)
{
	swap(a_head);
	swap(b_head);
	write(STDOUT_FILENO, "ss", 2);
}
