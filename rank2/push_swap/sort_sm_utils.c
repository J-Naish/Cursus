/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:39:59 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:28:30 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_min_node(t_stack *stack)
{
	t_node	*min;
	t_node	*current;

	if (!stack || is_empty(stack))
		return (NULL);
	min = stack->sentinel->next;
	current = min->next;
	while (current != stack->sentinel)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

static int	get_index(t_stack *stack, t_node *node)
{
	int		i;
	t_node	*current;

	if (!stack || !node)
		return (-1);
	i = 0;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		if (current == node)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

static void	move_node_to_top(t_stack *stack, t_node *node, char stack_name)
{
	int	index;
	int	size;
	int	j;

	if (!stack || !node)
		return ;
	size = get_stack_size(stack);
	index = get_index(stack, node);
	if (size == 0 || index == -1)
		return ;
	j = 0;
	if (index <= size / 2)
	{
		while (j++ < index)
			rotate_put(stack, stack_name);
	}
	else
	{
		while (j++ < size - index)
			rrotate_put(stack, stack_name);
	}
}

void	move_min_to_top(t_stack *stack, char stack_name)
{
	t_node	*min_node;

	min_node = get_min_node(stack);
	if (!min_node)
		return ;
	move_node_to_top(stack, min_node, stack_name);
}

// int main() {
// 	t_stack *stack = create_test_stack();

// 	t_node *minNode = get_min_node(stack);
// 	putstack(stack);
// 	ft_putstr("\n");
// 	putnode(minNode);
// 	ft_putstr("\n");
// 	int minIndex = get_index(stack, minNode);
// 	printf("%d\n", minIndex);

// 	size_t size = get_stack_size(stack);
// 	printf("%zu\n", size);

// 	move_node_to_top(stack, minNode, 'a');
// 	ft_putstr("\n");
// 	putstack(stack);
// }