/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:56:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 02:08:25 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list *list)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_first;

	if (!list)
		return ;
	if (list->sentinel->next == list->sentinel
		|| list->sentinel->next->next == list->sentinel)
		return ;
	first = list->sentinel->next;
	last = list->sentinel->prev;
	new_first = first->next;
	new_first->prev = list->sentinel;
	list->sentinel->prev = first;
	list->sentinel->next = new_first;
	first->next = list->sentinel;
	first->prev = last;
	last->next = first;
}

void	rra(t_list *list)
{
	reverse_rotate(list);
	ft_putstr("rra\n");
}

void	rrb(t_list *list)
{
	reverse_rotate(list);
	ft_putstr("rrb\n");
}

void	rrr(t_list *list_a, t_list *list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_putstr("rrr\n");
}

// int main() {
// 	t_list *listA = create_test_list();

// 	printf("initial stack a:\n");
// 	putlist_as_stack(listA);
// 	printf("\n");

// 	rra(listA);
// 	printf("\n");

// 	printf("after rra stack a:\n");
// 	putlist_as_stack(listA);
// 	printf("\n");
// }