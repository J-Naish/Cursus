/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:39:59 by nash              #+#    #+#             */
/*   Updated: 2025/02/04 04:46:03 by nash             ###   ########.fr       */
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

int	get_list_size(t_list *list)
{
	t_node	*current;
	int		len;

	if (!list || list->sentinel->next == list->sentinel)
		return (0);
	current = list->sentinel->next;
	len = 0;
	while (current != list->sentinel)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	move_node_to_top(t_list *list, t_node *node, char stack_name)
{
	int	index;
	int	size;
	int	j;

	if (!list || !node)
		return ;
	size = get_list_size(list);
	index = get_index(list, node);
	if (size == 0 || index == -1)
		return ;
	j = 0;
	if (index <= size / 2)
	{
		while (j++ < index)
			rotate_put(list, stack_name);
	}
	else
	{
		while (j++ < size - index)
			rrotate_put(list, stack_name);
	}
}

void	move_min_to_top(t_list *list, char stack_name)
{
	t_node	*min_node;

	min_node = get_min_node(list);
	if (!min_node)
		return ;
	move_node_to_top(list, min_node, stack_name);
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

// 	size_t size = get_list_size(list);
// 	printf("%zu\n", size);

// 	move_node_to_top(list, minNode, 'a');
// 	ft_putstr("\n");
// 	putlist_as_stack(list);
// }