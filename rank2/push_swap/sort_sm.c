/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:01:43 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:20:13 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_stack *stack)
{
	if (stack->sentinel->next->value > stack->sentinel->next->next->value)
		sa(stack);
}

static void	sort3(t_stack *stack, char stack_name)
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
		swap_put(stack, stack_name);
		rrotate_put(stack, stack_name);
	}
	else if (x > z && z > y)
		rotate_put(stack, stack_name);
	else if (y > z && z > x)
	{
		swap_put(stack, stack_name);
		ra(stack);
	}
	else if (y > x && x > z)
		rrotate_put(stack, stack_name);
	else if (z > x && x > y)
		swap_put(stack, stack_name);
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
	sort3(stack_a, 'a');
	while (pushed)
	{
		pa(stack_a, stack_b);
		pushed -= 1;
	}
}

void	sort_sm(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	if (size > 5)
		return ;
	else if (size == 1)
		return ;
	else if (size == 2)
		sort2(stack_a);
	else if (size == 3)
		sort3(stack_a, 'a');
	else
		sort5(stack_a, stack_b, size);
}
