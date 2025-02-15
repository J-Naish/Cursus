/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:05:24 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:28:20 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack)
		return ;
	if (is_empty(stack) || is_singleton(stack))
		return ;
	first = stack->sentinel->next;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	swap_put(t_stack *stack, char stack_name)
{
	swap(stack);
	ft_putchar('s');
	ft_putchar(stack_name);
	ft_putchar('\n');
}

void	sa(t_stack *stack)
{
	swap_put(stack, 'a');
}

void	sb(t_stack *stack)
{
	swap_put(stack, 'b');
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}

// int main() {
// 	t_stack *testA = create_test_stack();
// 	printf("initial stack a:\n");
// 	putstack(testA);
// 	printf("\n");
// 	sa(testA);
// 	printf("stack a after sa:\n");
// 	putstack(testA);
// 	printf("\n\n");

// 	t_stack *testB = create_test_stack();
// 	printf("initial stack b:\n");
// 	putstack(testB);
// 	sa(testB);
// 	printf("\n");
// 	printf("stack a after sb:\n");
// 	putstack(testB);
// 	printf("\n\n");

// 	printf("before ss:\n");
// 	printf("stack a:\n");
// 	putstack(testA);
// 	printf("\n");
// 	printf("stack b:\n");
// 	putstack(testB);
// 	printf("\n");

// 	ss(testA, testB);

// 	printf("after ss:\n");
// 	printf("stack a:\n");
// 	putstack(testA);
// 	printf("\n");
// 	printf("stack b:\n");
// 	putstack(testB);
// 	printf("\n");
// }