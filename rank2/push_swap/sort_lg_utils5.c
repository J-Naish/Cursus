/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort_lg_utils5.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nash <nash@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/16 21:03:28 by nash			  #+#	#+#			 */
/*   Updated: 2025/02/16 21:14:54 by nash			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static void	select_candidate(t_stack *a, t_stack *b,
	int *best_cost_a, int *best_cost_b)
{
	int		size_b;
	int		index;
	t_node	*curr;
	int		min_total_cost;
	int		candidate_total;

	size_b = get_stack_size(b);
	min_total_cost = INT_MAX;
	index = 0;
	curr = b->sentinel->next;
	while (curr != b->sentinel)
	{
		candidate_total = total_cost(rot_to_insert_a(a, curr->value),
				calculate_cost(index, size_b));
		if (candidate_total < min_total_cost)
		{
			min_total_cost = candidate_total;
			*best_cost_a = rot_to_insert_a(a, curr->value);
			*best_cost_b = calculate_cost(index, size_b);
		}
		curr = curr->next;
		index = index + 1;
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	best_cost_a;
	int	best_cost_b;

	while (get_stack_size(b) > 0)
	{
		best_cost_a = 0;
		best_cost_b = 0;
		select_candidate(a, b, &best_cost_a, &best_cost_b);
		perform_rot(a, b, best_cost_a, best_cost_b);
		pa(a, b);
	}
}
