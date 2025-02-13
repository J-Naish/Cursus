/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:56:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 05:03:01 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list *list)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_last;

	if (!list)
		return ;
	if (is_empty(list) || is_singleton(list))
		return ;
	first = list->sentinel->next;
	last = list->sentinel->prev;
	new_last = last->prev;
	last->prev = list->sentinel;
	last->next = first;
	first->prev = last;
	list->sentinel->next = last;
	list->sentinel->prev = new_last;
	new_last->next = list->sentinel;
}

void	rrotate_put(t_list *list, char stack_name)
{
	reverse_rotate(list);
	ft_putstr("rr");
	ft_putchar(stack_name);
	ft_putchar('\n');
}

void	rra(t_list *list)
{
	rrotate_put(list, 'a');
}

void	rrb(t_list *list)
{
	rrotate_put(list, 'b');
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