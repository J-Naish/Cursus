/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:27:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/28 20:06:36 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putint(int num)
{
	long long	casted_num;

	casted_num = (long long)num;
	if (casted_num < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		casted_num *= -1;
	}
	if (casted_num < 10)
	{
		ft_putchar_fd('0' + casted_num, STDOUT_FILENO);
	}
	if (casted_num >= 10)
	{
		putint(casted_num / 10);
		putint(casted_num % 10);
	}
}

void	putnode(t_node *node)
{
	if (!node)
		return ;
	putint(node->value);
}

void	putstack(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->sentinel->next;
	while (current != stack->sentinel)
	{
		putnode(current);
		current = current->next;
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

t_stack	*create_test_stack(void)
{
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (NULL);
	append_node(stack, 42);
	append_node(stack, -42);
	append_node(stack, 123);
	append_node(stack, 0);
	append_node(stack, 12345);
	append_node(stack, -67890);
	append_node(stack, INT_MAX);
	append_node(stack, INT_MIN);
	return (stack);
}
