/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:27:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 00:10:47 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

static void	putint(int num)
{
	long long	casted_num;

	casted_num = (long long)num;
	if (casted_num < 0)
	{
		ft_putchar('-');
		casted_num *= -1;
	}
	if (casted_num < 10)
	{
		ft_putchar('0' + casted_num);
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

void	putlist(t_list *list)
{
	t_node	*current;

	if (!list)
		return ;
	current = list->sentinel->next;
	while (current != list->sentinel)
	{
		putnode(current);
		current = current->next;
		if (current != list->sentinel)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

t_list	*create_test_list(void)
{
	t_list	*list;

	list = create_list();
	if (!list)
		return (NULL);
	append_node(list, 42);
	append_node(list, -42);
	append_node(list, 123);
	append_node(list, 0);
	append_node(list, 12345);
	append_node(list, -67890);
	append_node(list, INT_MAX);
	append_node(list, INT_MIN);
	return (list);
}

// int main() {
// 	// putintのテストケース
// 	// 引数は必ずint型であると想定
// 	int numCases[] = {
// 		0, 1, -2, 4, 100, 12345, -5483, INT_MAX, INT_MIN
// 	};

// 	for (int i = 0; i < sizeof(numCases) / sizeof(int); i++) {
// 		printf("Expected: %d\n", numCases[i]);
// 		printf("Result  : ");
// 		fflush(stdout);
// 		putint(numCases[i]);
// 		printf("\n\n");
// 	}
// }