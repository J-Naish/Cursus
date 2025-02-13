/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:40:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 04:53:18 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepend_node(t_list *list, int value)
{
	t_node	*new;
	t_node	*first;

	if (!list)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	first = list->sentinel->next;
	new->value = value;
	new->next = first;
	new->prev = list->sentinel;
	list->sentinel->next = new;
	first->prev = new;
}

void	append_node(t_list *list, int value)
{
	t_node	*new;
	t_node	*last;

	if (!list)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	last = list->sentinel->prev;
	new->value = value;
	new->next = list->sentinel;
	new->prev = last;
	list->sentinel->prev = new;
	last->next = new;
}

void	shift_node(t_list *list)
{
	t_node	*first;

	if (!list)
		return ;
	first = list->sentinel->next;
	first->next->prev = list->sentinel;
	list->sentinel->next = first->next;
	free(first);
}

void	pop_node(t_list *list)
{
	t_node	*last;

	if (!list)
		return ;
	last = list->sentinel->prev;
	last->prev->next = list->sentinel;
	list->sentinel->prev = last->prev;
	free(last);
}

// int main() {
//   t_list* list = init_list();
//   if (!list) perror("malloc fails");

//   int nums[] = {
// 	0, -1, 1, 42, -42, 12345, -67890, INT_MIN, INT_MAX,
// 	534, 356, 8901, -8532, 573
//   };

//   for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
// 	append_node(list, nums[i]);
//   }

//   putlist(list);
//   printf("\n");

//   pop_node(list);
//   putlist(list);
//   printf("\n");

//   prepend_node(list, 100);
//   putlist(list);
//   printf("\n");

//   shift_node(list);
//   putlist(list);
//   printf("\n");

// }