/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:20:13 by nash              #+#    #+#             */
/*   Updated: 2025/02/27 07:28:44 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->sentinel->next;
	while (current->next != stack->sentinel)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	exit_if_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a) || is_empty(stack_a))
		return ;
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_SUCCESS);
	}
}
