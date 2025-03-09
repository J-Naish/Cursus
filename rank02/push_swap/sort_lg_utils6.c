/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:19:03 by nash              #+#    #+#             */
/*   Updated: 2025/02/22 23:11:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_to_top(t_stack *a)
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
