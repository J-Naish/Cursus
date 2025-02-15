/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:40:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:28:33 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepend_node(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*first;

	if (!stack)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	first = stack->sentinel->next;
	new->value = value;
	new->next = first;
	new->prev = stack->sentinel;
	stack->sentinel->next = new;
	first->prev = new;
}

void	append_node(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*last;

	if (!stack)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	last = stack->sentinel->prev;
	new->value = value;
	new->next = stack->sentinel;
	new->prev = last;
	stack->sentinel->prev = new;
	last->next = new;
}

void	shift_node(t_stack *stack)
{
	t_node	*first;

	if (!stack)
		return ;
	first = stack->sentinel->next;
	first->next->prev = stack->sentinel;
	stack->sentinel->next = first->next;
	free(first);
}

void	pop_node(t_stack *stack)
{
	t_node	*last;

	if (!stack)
		return ;
	last = stack->sentinel->prev;
	last->prev->next = stack->sentinel;
	stack->sentinel->prev = last->prev;
	free(last);
}

// int main() {
//   t_stack* stack = init_stack();
//   if (!stack) perror("malloc fails");

//   int nums[] = {
// 	0, -1, 1, 42, -42, 12345, -67890, INT_MIN, INT_MAX,
// 	534, 356, 8901, -8532, 573
//   };

//   for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
// 	append_node(stack, nums[i]);
//   }

//   putstack(stack);
//   printf("\n");

//   pop_node(stack);
//   putstack(stack);
//   printf("\n");

//   prepend_node(stack, 100);
//   putstack(stack);
//   printf("\n");

//   shift_node(stack);
//   putstack(stack);
//   printf("\n");

// }