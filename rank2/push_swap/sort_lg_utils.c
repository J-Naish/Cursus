/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:07:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:41:48 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_arr(t_stack *stack)
{
	int		size;
	int		*arr;
	t_node	*current;
	int		i;

	size = get_stack_size(stack);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
	{
		free(stack);
		exit(EXIT_FAILURE);
	}
	current = stack->sentinel->next;
	i = 0;
	while (current != stack->sentinel)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	normalize_stack(t_stack *stack)
{
	int		*arr;
	int		size;
	t_node	*current;
	int		i;

	current = stack->sentinel->next;
	arr = get_arr(stack);
	size = get_stack_size(stack);
	quick_sort(arr, size);
	while (current != stack->sentinel)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == arr[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(arr);
}

// int main() {
// 	t_stack *stack = create_test_stack();
// 	putstack(stack);
// 	printf("\n");
// 	normalize_stack(stack);
// 	putstack(stack);
// }