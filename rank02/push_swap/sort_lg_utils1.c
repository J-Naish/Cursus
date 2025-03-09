/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:07:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 19:33:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, t_node *node)
{
	int		index;
	t_node	*current;

	index = 0;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current == node)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (get_stack_size(stack) == 0)
		return (-1);
	max = stack->sentinel->next->value;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (get_stack_size(stack) == 0)
		return (-1);
	min = stack->sentinel->next->value;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_index_of_max(t_stack *stack)
{
	int		index;
	int		max_index;
	int		size;
	int		max;
	t_node	*current;

	index = 0;
	max_index = 0;
	size = get_stack_size(stack);
	if (size == 0)
		return (-1);
	max = stack->sentinel->next->value;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current->value > max)
		{
			max = current->value;
			max_index = index;
		}
		index++;
		current = current->next;
	}
	return (max_index);
}

int	find_index_of_min(t_stack *stack)
{
	int		index;
	int		min_index;
	int		size;
	int		min;
	t_node	*current;

	index = 0;
	min_index = 0;
	size = get_stack_size(stack);
	if (size == 0)
		return (-1);
	min = stack->sentinel->next->value;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = index;
		}
		index++;
		current = current->next;
	}
	return (min_index);
}
