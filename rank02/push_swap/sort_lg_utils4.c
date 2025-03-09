/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:49:13 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 21:02:13 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_next_node(t_stack *a, t_node *curr, int index, int size)
{
	if (index == size - 1)
		return (a->sentinel->next);
	else
		return (curr->next);
}

static int	is_break_gap(t_node *current, t_node *next, int value)
{
	if (current->value > next->value)
	{
		if (value > current->value || value < next->value)
			return (1);
	}
	return (0);
}

static int	is_normal_gap(t_node *current, t_node *next, int value)
{
	if (value > current->value && value < next->value)
		return (1);
	return (0);
}

int	rot_to_insert_a(t_stack *a, int value)
{
	int		size;
	int		i;
	t_node	*current;
	t_node	*next;
	int		min_index;

	size = get_stack_size(a);
	if (size == 0)
		return (0);
	current = a->sentinel->next;
	i = 0;
	while (i < size)
	{
		next = get_next_node(a, current, i, size);
		if (is_break_gap(current, next, value))
			return (calculate_cost(i + 1, size));
		if (is_normal_gap(current, next, value))
			return (calculate_cost(i + 1, size));
		current = current->next;
		i++;
	}
	min_index = find_index_of_min(a);
	return (calculate_cost(min_index, size));
}
