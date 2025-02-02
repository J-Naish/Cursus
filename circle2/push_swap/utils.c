/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:40:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/02 21:29:33 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->sentinel = (t_node *)malloc(sizeof(t_node));
	if (!list->sentinel)
		return (free(list), NULL);
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	return (list);
}

void	insert_node(t_node *node, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;
}

void	append_node(t_list *list, int value)
{
	insert_node(list->sentinel->prev, value);
}

void	remove_node(t_node *node)
{
	if (!node)
		return ;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

void	pop_node(t_list *list)
{
	remove_node(list->sentinel->prev);
}

int main() {
  t_list* list = create_list();
  if (!list) perror("malloc fails");

  int nums[] = {
	0, -1, 1, 42, -42, 12345, -67890, INT_MIN, INT_MAX
  };

  for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
	append_node(list, nums[i]);
  }

  putlist(list);

}