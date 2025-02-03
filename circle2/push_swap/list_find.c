/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:39:59 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 14:14:31 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min_node(t_list *list)
{
	t_node	*min;
	t_node	*current;

	if (!list || list->sentinel->next == list->sentinel)
		return (NULL);
	min = list->sentinel->next;
	current = min->next;
	while (current != list->sentinel)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

// int main() {
// 	t_list *list = create_test_list();

// 	t_node *minNode = get_min_node(list);
// 	putlist_as_stack(list);
// 	ft_putstr("\n");
// 	putnode(minNode);
// 	ft_putstr("\n");
// }