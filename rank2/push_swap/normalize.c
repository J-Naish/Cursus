/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:07:23 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 05:40:02 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_arr(t_list *list)
{
	int		size;
	int		*arr;
	t_node	*current;
	int		i;

	size = get_list_size(list);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
	{
		free(list);
		exit(EXIT_FAILURE);
	}
	current = list->sentinel->next;
	i = 0;
	while (current != list->sentinel)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	normalize_list(t_list *list)
{
	int		*arr;
	int		size;
	t_node	*current;
	int		i;

	current = list->sentinel->next;
	arr = get_arr(list);
	size = get_list_size(list);
	quick_sort(arr, size);
	while (current != list->sentinel)
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

int main() {
	t_list *list = create_test_list();
	putlist_as_stack(list);
	printf("\n");
	normalize_list(list);
	putlist_as_stack(list);
}