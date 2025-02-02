/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 05:01:43 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 05:08:04 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_list *list)
{
	if (!list)
		exit(EXIT_FAILURE);
	if (list->sentinel->next->value > list->sentinel->next->next->value)
		sa(list);
	exit(EXIT_SUCCESS);
}

void	sort_sm(t_list *list_a, t_list *list_b, int size)
{
	if (!list_a || !list_b)
		exit(EXIT_FAILURE);
	if (size == 2)
		sort2(list_a);
}
