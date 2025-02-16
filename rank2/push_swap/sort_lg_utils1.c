/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:07:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 09:42:17 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_in_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
	t_node	*current;

	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current->value >= chunk_min && current->value <= chunk_max)
			return (true);
		current = current->next;
	}
	return (false);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (is_empty(stack))
		return (-1);
	current = stack->sentinel->next;
	max = current->value;
	current = current->next;
	while (current != stack->sentinel)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_index_of_value(t_stack *stack, int value)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current->value == value)
			break ;
		i++;
		current = current->next;
	}
	return (i);
}

// int main() {
// 	t_stack *stack = create_test_stack();
// 	putstack(stack);
// 	printf("\n");
// 	normalize_stack(stack);
// 	putstack(stack);
// }