/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:13:54 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 05:03:14 by nash             ###   ########.fr       */
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
	if (is_empty(list) || is_singleton(list))
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

void	rotate_put(t_list *list, char stack_name)
{
	rotate(list);
	ft_putchar('r');
	ft_putchar(stack_name);
	ft_putchar('\n');
}

void	ra(t_list *list)
{
	rotate_put(list, 'a');
}

void	rb(t_list *list)
{
	rotate_put(list, 'b');
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