/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:09:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 21:19:15 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		perform_rot(a, b, best_cost_a, best_cost_b);
		pb(a, b);
	}
	sort3(a, 'a');
	push_back_to_a(a, b);
	final_arrangement(a);
}
