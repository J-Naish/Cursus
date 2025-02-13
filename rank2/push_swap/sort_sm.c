/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:01:43 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 04:49:15 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_list *list)
{
	if (list->sentinel->next->value > list->sentinel->next->next->value)
		sa(list);
}

static void	sort3(t_list *list, char stack_name)
{
	int	x;
	int	y;
	int	z;

	x = list->sentinel->next->value;
	y = list->sentinel->next->next->value;
	z = list->sentinel->next->next->next->value;
	if (y > x && z > y)
		return ;
	else if (x > y && y > z)
	{
		swap_put(list, stack_name);
		rrotate_put(list, stack_name);
	}
	else if (x > z && z > y)
		rotate_put(list, stack_name);
	else if (y > z && z > x)
	{
		swap_put(list, stack_name);
		ra(list);
	}
	else if (y > x && x > z)
		rrotate_put(list, stack_name);
	else if (z > x && x > y)
		swap_put(list, stack_name);
}

static void	sort5(t_list *list_a, t_list *list_b, int size)
{
	int	pushed;

	pushed = 0;
	while (size - pushed > 3)
	{
		move_min_to_top(list_a, 'a');
		pb(list_a, list_b);
		pushed += 1;
	}
	sort3(list_a, 'a');
	while (pushed)
	{
		pa(list_a, list_b);
		pushed -= 1;
	}
}

void	sort_sm(t_list *list_a, t_list *list_b, int size)
{
	if (!list_a || !list_b)
		exit(EXIT_FAILURE);
	if (size > 5)
		return ;
	else if (size == 1)
		return ;
	else if (size == 2)
		sort2(list_a);
	else if (size == 3)
		sort3(list_a, 'a');
	else
		sort5(list_a, list_b, size);
}
