/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:09:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:28:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	max_bits;
	int	count;
	int	i;
	int	num;

	max_bits = 0;
	while (((size_a - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		count = size_a;
		while (count--)
		{
			num = stack_a->sentinel->next->value;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (get_stack_size(stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_lg(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	normalize_stack(stack_a);
	size_a = get_stack_size(stack_a);
	radix_sort(stack_a, stack_b, size_a);
}
