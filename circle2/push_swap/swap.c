/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:05:24 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 01:40:41 by nash             ###   ########.fr       */
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
	if (list->sentinel->next == list->sentinel
		|| list->sentinel->next->next == list->sentinel)
		return ;
	first = list->sentinel->next;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	sa(t_list *list)
{
	swap(list);
	ft_putstr("sa\n");
}

void	sb(t_list *list)
{
	swap(list);
	ft_putstr("sb\n");
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