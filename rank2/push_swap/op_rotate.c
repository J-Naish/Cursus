/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:13:54 by nash              #+#    #+#             */
/*   Updated: 2025/02/28 20:07:11 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;
	t_node	*new_first;

	if (!stack)
		return ;
	if (is_empty(stack) || is_singleton(stack))
		return ;
	last = stack->sentinel->prev;
	first = stack->sentinel->next;
	new_first = first->next;
	first->next = stack->sentinel;
	first->prev = last;
	stack->sentinel->prev = first;
	stack->sentinel->next = new_first;
	last->next = first;
}

void	rotate_put(t_stack *stack, char stack_name)
{
	rotate(stack);
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ra(t_stack *stack)
{
	rotate_put(stack, 'a');
}

void	rb(t_stack *stack)
{
	rotate_put(stack, 'b');
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
