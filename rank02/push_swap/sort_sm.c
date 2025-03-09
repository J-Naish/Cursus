/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:01:43 by nash              #+#    #+#             */
/*   Updated: 2025/02/26 03:45:25 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_stack *stack)
{
	if (stack->sentinel->next->value > stack->sentinel->next->next->value)
		sa(stack);
}

void	sort3(t_stack *stack)
{
	int	x;
	int	y;
	int	z;

	x = stack->sentinel->next->value;
	y = stack->sentinel->next->next->value;
	z = stack->sentinel->next->next->next->value;
	if (y > x && z > y)
		return ;
	else if (x > y && y > z)
	{
		sa(stack);
		rra(stack);
	}
	else if (x > z && z > y)
		ra(stack);
	else if (y > z && z > x)
	{
		sa(stack);
		ra(stack);
	}
	else if (y > x && x > z)
		rra(stack);
	else if (z > x && x > y)
		sa(stack);
}

static void	sort5(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pushed;

	pushed = 0;
	while (size - pushed > 3)
	{
		move_min_to_top(stack_a, 'a');
		pb(stack_a, stack_b);
		pushed += 1;
	}
	sort3(stack_a);
	while (pushed)
	{
		pa(stack_a, stack_b);
		pushed -= 1;
	}
}

void	sort_sm(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort2(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else
		sort5(stack_a, stack_b, size);
}
