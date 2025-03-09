/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:15:04 by nash              #+#    #+#             */
/*   Updated: 2025/02/28 20:06:47 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *to, t_stack *from)
{
	int		value;

	if (!to || !from)
		return ;
	if (from->sentinel->next == from->sentinel)
		return ;
	value = from->sentinel->next->value;
	shift_node(from);
	prepend_node(to, value);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
