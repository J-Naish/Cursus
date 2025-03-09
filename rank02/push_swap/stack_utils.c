/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 07:30:45 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:30:47 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->sentinel = (t_node *)malloc(sizeof(t_node));
	if (!stack->sentinel)
	{
		free(stack);
		exit(EXIT_FAILURE);
	}
	stack->sentinel->next = stack->sentinel;
	stack->sentinel->prev = stack->sentinel;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack->sentinel);
	free(stack);
}

bool	is_empty(t_stack *stack)
{
	if (stack->sentinel->next == stack->sentinel)
		return (true);
	else
		return (false);
}

bool	is_singleton(t_stack *stack)
{
	if (stack->sentinel->next->next == stack->sentinel)
		return (true);
	else
		return (false);
}

int	get_stack_size(t_stack *stack)
{
	t_node	*current;
	int		len;

	if (!stack || is_empty(stack))
		return (0);
	current = stack->sentinel->next;
	len = 0;
	while (current != stack->sentinel)
	{
		len++;
		current = current->next;
	}
	return (len);
}
