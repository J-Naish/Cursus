/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:01:43 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 06:17:20 by nash             ###   ########.fr       */
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
	int	value1;
	int	value2;
	int	value3;

	value1 = list->sentinel->next->value;
	value2 = list->sentinel->next->next->value;
	value3 = list->sentinel->next->next->next->value;
	if (value2 > value1 && value3 > value2)
		return ;
	else if (value1 > value2 && value2 > value3)
	{
		sa(list);
		rra(list);
	}
	else if (value1 > value3 && value3 > value2)
		ra(list);
	else if (value2 > value3 && value3 > value1)
	{
		sa(list);
		ra(list);
	}
	else if (value2 > value1 && value1 > value3)
		rra(list);
	else if (value3 > value1 && value1 > value2)
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
