/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:13:54 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 04:53:23 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *list)
{
	t_node	*last;
	t_node	*first;
	t_node	*new_first;

	if (!list)
		return ;
	if (list->sentinel->next == list->sentinel
		|| list->sentinel->next->next == list->sentinel)
		return ;
	last = list->sentinel->prev;
	first = list->sentinel->next;
	new_first = first->next;
	first->next = list->sentinel;
	first->prev = last;
	list->sentinel->prev = first;
	list->sentinel->next = new_first;
	last->next = first;
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