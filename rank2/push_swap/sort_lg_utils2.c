/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:45 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 21:11:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (index - size);
}

int	total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	if (cost_a < 0)
		abs_a = -cost_a;
	else
		abs_a = cost_a;
	if (cost_b < 0)
		abs_b = -cost_b;
	else
		abs_b = cost_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}

int	find_insert_position_in_b(t_stack *b, int value)
{
	int		max_index;
	int		pos;
	int		index;
	t_node	*current;

	if (get_stack_size(b) == 0)
		return (0);
	if (value > find_max(b) || value < find_min(b))
	{
		max_index = find_index_of_max(b);
		pos = max_index + 1;
		if (pos >= get_stack_size(b))
			pos = 0;
		return (pos);
	}
	index = 0;
	current = b->sentinel->next;
	while (current != b->sentinel)
	{
		if (value < current->value)
			return (index);
		index++;
		current = current->next;
	}
	return (0);
}
