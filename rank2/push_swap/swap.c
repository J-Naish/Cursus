/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:05:24 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 05:03:28 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *list)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!list)
		return ;
	if (is_empty(list) || is_singleton(list))
		return ;
	first = list->sentinel->next;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	swap_put(t_list *list, char stack_name)
{
	swap(list);
	ft_putchar('s');
	ft_putchar(stack_name);
	ft_putchar('\n');
}

void	sa(t_list *list)
{
	swap_put(list, 'a');
}

void	sb(t_list *list)
{
	swap_put(list, 'b');
}

void	ss(t_list *list_a, t_list *list_b)
{
	swap(list_a);
	swap(list_b);
	ft_putstr("ss\n");
}

// int main() {
// 	t_list *testA = create_test_list();
// 	printf("initial list a:\n");
// 	putlist(testA);
// 	printf("\n");
// 	sa(testA);
// 	printf("list a after sa:\n");
// 	putlist(testA);
// 	printf("\n\n");

// 	t_list *testB = create_test_list();
// 	printf("initial list b:\n");
// 	putlist(testB);
// 	sa(testB);
// 	printf("\n");
// 	printf("list a after sb:\n");
// 	putlist(testB);
// 	printf("\n\n");

// 	printf("before ss:\n");
// 	printf("list a:\n");
// 	putlist(testA);
// 	printf("\n");
// 	printf("list b:\n");
// 	putlist(testB);
// 	printf("\n");

// 	ss(testA, testB);

// 	printf("after ss:\n");
// 	printf("list a:\n");
// 	putlist(testA);
// 	printf("\n");
// 	printf("list b:\n");
// 	putlist(testB);
// 	printf("\n");
// }