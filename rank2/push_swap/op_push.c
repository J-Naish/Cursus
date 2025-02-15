/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:15:04 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:28:16 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *to, t_stack *from)
{
	int		value;

	if (!to || !from)
		return ;
	if (from->sentinel->next == from->sentinel)
		return ;
	value = from->sentinel->next->value;
	shift_node(from);
	prepend_node(to, value);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pb\n");
}

// int main() {
// 	t_stack *stackA = create_test_stack();
// 	t_stack *stackB = create_test_stack();

// 	printf("initial stack a: \n");
// 	putstack(stackA);
// 	printf("\n");
// 	printf("initial stack b: \n");
// 	putstack(stackB);
// 	printf("\n\n");

// 	pa(stackA, stackB);

// 	printf("after pa stack A: \n");
// 	putstack(stackA);
// 	printf("\n");
// 	printf("after pa stack b: \n");
// 	putstack(stackB);
// 	printf("\n\n");

// 	pb(stackA, stackB);

// 	printf("after pb stack A: \n");
// 	putstack(stackA);
// 	printf("\n");
// 	printf("after pb stack b: \n");
// 	putstack(stackB);
// 	printf("\n\n");
// }