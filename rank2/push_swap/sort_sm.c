/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:01:43 by nash              #+#    #+#             */
/*   Updated: 2025/02/04 02:59:41 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_list *list)
{
	if (list->sentinel->next->value > list->sentinel->next->next->value)
		sa(list);
}

static void	sort3(t_list *list)
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
		sa(list);
		rra(list);
	}
	else if (x > z && z > y)
		ra(list);
	else if (y > z && z > x)
	{
		sa(list);
		ra(list);
	}
	else if (y > x && x > z)
		rra(list);
	else if (z > x && x > y)
		sa(list);
}



void	sort_sm(t_list *list_a, t_list *list_b, int size)
{
	if (!list_a || !list_b)
		exit(EXIT_FAILURE);
	if (size == 2)
		sort2(list_a);
	if (size == 3)
		sort3(list_a);
	free_list(list_a);
	free_list(list_b);
	exit(EXIT_SUCCESS);
}
