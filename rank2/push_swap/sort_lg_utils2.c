/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:26:37 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 09:38:56 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b, int size, int chunk_size)
{
	int	i;
	int	min;
	int	max;
	int	mid;

	i = 0;
	while (i < size)
	{
		min = i;
		max = i + chunk_size - 1;
		if (max >= size)
			max = size - 1;
		mid = (min + max) / 2;
		while (has_in_chunk(a, min, max))
		{
			if (a->sentinel->next->value >= min
				&& a->sentinel->next->value <= max)
			{
				pb(a, b);
				if (b->sentinel->next->value < mid)
					rb(b);
			}
			else
				ra(a);
		}
		i += chunk_size;
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;
	int	b_size;
	int	r;

	while (get_stack_size(b) > 0)
	{
		max = find_max(b);
		pos = get_index_of_value(b, max);
		b_size = get_stack_size(b);
		if (pos <= b_size / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			r = b_size - pos;
			while (r-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk_size;

	size = get_stack_size(a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(a, b, size, chunk_size);
	push_back_to_a(a, b);
}
