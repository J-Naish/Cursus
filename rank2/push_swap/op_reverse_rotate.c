/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:56:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/28 20:07:01 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_last;

	if (!stack)
		return ;
	if (is_empty(stack) || is_singleton(stack))
		return ;
	first = stack->sentinel->next;
	last = stack->sentinel->prev;
	new_last = last->prev;
	last->prev = stack->sentinel;
	last->next = first;
	first->prev = last;
	stack->sentinel->next = last;
	stack->sentinel->prev = new_last;
	new_last->next = stack->sentinel;
}

void	rrotate_put(t_stack *stack, char stack_name)
{
	reverse_rotate(stack);
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	rra(t_stack *stack)
{
	rrotate_put(stack, 'a');
}

void	rrb(t_stack *stack)
{
	rrotate_put(stack, 'b');
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
