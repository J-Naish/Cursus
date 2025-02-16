/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:45 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 19:42:40 by nash             ###   ########.fr       */
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

static int	get_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = get_abs(cost_a);
	abs_b = get_abs(cost_b);
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
	int		size;
	int		min;
	int		max;
	int		max_index;
	int		pos;
	int		index;
	t_node	*current;

	size = get_stack_size(b);
	if (size == 0)
		return (0);
	max = find_max(b);
	min = find_min(b);
	if (value > max || value < min)
	{
		max_index = find_index_of_max(b);
		pos = max_index + 1;
		if (pos >= size)
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

