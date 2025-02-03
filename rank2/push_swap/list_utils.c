/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:39:59 by nash              #+#    #+#             */
/*   Updated: 2025/02/04 04:02:43 by nash             ###   ########.fr       */
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

int	get_index(t_list *list, t_node *node)
{
	int		i;
	t_node	*current;

	if (!list || !node)
		return (-1);
	i = 0;
	current = list->sentinel->next;
	while (current != list->sentinel)
	{
		if (current == node)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

// int main() {
// 	t_list *list = create_test_list();

// 	t_node *minNode = get_min_node(list);
// 	putlist_as_stack(list);
// 	ft_putstr("\n");
// 	putnode(minNode);
// 	ft_putstr("\n");
// 	int minIndex = get_index(list, minNode);
// 	printf("%d\n", minIndex);
// }