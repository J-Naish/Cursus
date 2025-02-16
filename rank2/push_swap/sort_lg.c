/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:25:00 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 21:25:03 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	candidate_cost(t_stack *a, t_stack *b, t_node *node, int index)
{
	int	size;
	int	cost_a;
	int	pos_in_b;
	int	size_b;
	int	cost_b;

	size = get_stack_size(a);
	cost_a = calculate_cost(index, size);
	pos_in_b = find_insert_position_in_b(b, node->value);
	size_b = get_stack_size(b);
	cost_b = calculate_cost(pos_in_b, size_b);
	return (total_cost(cost_a, cost_b));
}

static void	select_candidate_a(t_stack *a, t_stack *b,
	int *best_cost_a, int *best_cost_b)
{
	t_node	*curr;
	int		index;
	int		min_total_cost;
	int		candidate_total;

	min_total_cost = INT_MAX;
	index = 0;
	curr = a->sentinel->next;
	while (curr != a->sentinel)
	{
		candidate_total = candidate_cost(a, b, curr, index);
		if (candidate_total < min_total_cost)
		{
			min_total_cost = candidate_total;
			*best_cost_a = calculate_cost(index, get_stack_size(a));
			*best_cost_b = calculate_cost(
					find_insert_position_in_b(b, curr->value),
					get_stack_size(b));
		}
		curr = curr->next;
		index = index + 1;
	}
}

void	sort_lg(t_stack *a, t_stack *b)
{
	int	size;
	int	best_cost_a;
	int	best_cost_b;

	pb(a, b);
	pb(a, b);
	size = get_stack_size(a);
	while (size > 3)
	{
		best_cost_a = 0;
		best_cost_b = 0;
		select_candidate_a(a, b, &best_cost_a, &best_cost_b);
		perform_rot(a, b, best_cost_a, best_cost_b);
		pb(a, b);
		size = get_stack_size(a);
	}
	sort3(a, 'a');
	push_back_to_a(a, b);
	final_arrangement(a);
}
