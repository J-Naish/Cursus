/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:15:04 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 01:12:35 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *to, t_list *from)
{
	int		value;

	if (!to || !from)
		return ;
	if (from->sentinel->next == from->sentinel)
		return ;
	value = from->sentinel->prev->value;
	pop_node(from);
	append_node(to, value);
}

void	pa(t_list *list_a, t_list *list_b)
{
	push(list_a, list_b);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_list *list_a, t_list *list_b)
{
	push(list_b, list_a);
	write(STDOUT_FILENO, "pb\n", 3);
}

// int main() {
// 	t_list *listA = create_test_list();
// 	t_list *listB = create_test_list();

// 	printf("initial list a: \n");
// 	putlist(listA);
// 	printf("\n");
// 	printf("initial list b: \n");
// 	putlist(listB);
// 	printf("\n\n");

// 	pa(listA, listB);

// 	printf("after pa list A: \n");
// 	putlist(listA);
// 	printf("\n");
// 	printf("after pa list b: \n");
// 	putlist(listB);
// 	printf("\n\n");

// 	pb(listA, listB);

// 	printf("after pb list A: \n");
// 	putlist(listA);
// 	printf("\n");
// 	printf("after pb list b: \n");
// 	putlist(listB);
// 	printf("\n\n");
// }