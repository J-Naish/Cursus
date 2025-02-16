/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:41:47 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 20:47:18 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_helper(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		*cost_a -= 1;
		*cost_b -= 1;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		*cost_a += 1;
		*cost_b += 1;
	}
}

void	perform_rot(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	rot_helper(a, b, &cost_a, &cost_b);
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
