/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:13:54 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 01:56:04 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *list)
{
	t_node	*last;
	t_node	*first;
	t_node	*new_last;

	if (!list)
		return ;
	if (list->sentinel->next == list->sentinel
		|| list->sentinel->next->next == list->sentinel)
		return ;
	last = list->sentinel->prev;
	first = list->sentinel->next;
	new_last = last->prev;
	new_last->next = list->sentinel;
	list->sentinel->prev = new_last;
	last->next = first;
	last->prev = list->sentinel;
	first->prev = last;
	list->sentinel->next = last;
}

void	ra(t_list *list)
{
	rotate(list);
	ft_putstr("ra\n");
}

void	rb(t_list *list)
{
	rotate(list);
	ft_putstr("rb\n");
}

void	rr(t_list *list_a, t_list *list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_putstr("rr\n");
}

// int main() {
// 	t_list *listA = create_test_list();

// 	printf("initial stack a:\n");
// 	putlist_as_stack(listA);
// 	printf("\n");

// 	ra(listA);
// 	printf("\n");

// 	printf("after ra stack a:\n");
// 	putlist_as_stack(listA);
// 	printf("\n");
// }