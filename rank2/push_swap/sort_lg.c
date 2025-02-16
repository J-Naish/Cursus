/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:09:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 19:55:40 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void perform_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

int	rotations_to_insert_a(t_stack *a, int value)
{
	int		size;
	int		i;
	t_node	*current;
	int		min_value;
	int		max_value;
	int		min_index;

	size = get_stack_size(a);
	i = 0;
	current = a->sentinel->next;
	min_value = find_min(a);
	max_value = find_max(a);
	if (value < min_value || value > max_value)
	{
		min_index = find_index_of_min(a);
		return (calculate_cost(min_index, size));
	}
	while (i < size)
	{
		if (current->value > value)
			return (calculate_cost(i, size));
		current = current->next;
		i++;
	}
	return (0);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	cost;

	while (get_stack_size(b) > 0)
	{
		cost = rotations_to_insert_a(a, b->sentinel->next->value);
		while (cost > 0)
		{
			ra(a);
			cost--;
		}
		while (cost < 0)
		{
			rra(a);
			cost++;
		}
		pa(a, b);
	}
}

void	final_arrangement(t_stack *a)
{
	int	min_index;
	int	size;
	int	cost;

	min_index = find_index_of_min(a);
	size = get_stack_size(a);
	cost = calculate_cost(min_index, size);
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
}

void	sort_lg(t_stack *a, t_stack *b)
{
	int size;

	pb(a, b);
	pb(a, b);
	while ((size = get_stack_size(a)) > 3)
	{
		t_node *curr = a->sentinel->next;
		int index = 0;
		int min_total_cost = INT_MAX;
		int best_cost_a = 0;
		int best_cost_b = 0;
		while (curr != a->sentinel)
		{
			int cost_a = calculate_cost(index, size);
			int pos_in_b = find_insert_position_in_b(b, curr->value);
			int size_b = get_stack_size(b);
			int cost_b = calculate_cost(pos_in_b, size_b);
			int current_total_cost = total_cost(cost_a, cost_b);
			if (current_total_cost < min_total_cost)
			{
				min_total_cost = current_total_cost;
				best_cost_a = cost_a;
				best_cost_b = cost_b;
			}
			curr = curr->next;
			index++;
		}
		perform_rotations(a, b, best_cost_a, best_cost_b);
		pb(a, b);
	}
	sort3(a, 'a');
	push_back_to_a(a, b);
	final_arrangement(a);
}
