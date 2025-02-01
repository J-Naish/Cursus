/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:27:35 by nash              #+#    #+#             */
/*   Updated: 2025/02/01 21:14:13 by nash             ###   ########.fr       */
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

void	putstack(t_node *head)
{
	struct t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		putint(tmp->value);
		ft_putchar('\n');
		tmp = tmp->next;
	}
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