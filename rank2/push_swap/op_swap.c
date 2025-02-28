/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:05:24 by nash              #+#    #+#             */
/*   Updated: 2025/02/28 20:07:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack)
		return ;
	if (is_empty(stack) || is_singleton(stack))
		return ;
	first = stack->sentinel->next;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	swap_put(t_stack *stack, char stack_name)
{
	swap(stack);
	ft_putchar_fd('s', STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	sa(t_stack *stack)
{
	swap_put(stack, 'a');
}

void	sb(t_stack *stack)
{
	swap_put(stack, 'b');
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
