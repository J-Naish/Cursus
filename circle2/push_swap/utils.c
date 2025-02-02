/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:40:01 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 04:22:06 by nash             ###   ########.fr       */
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

  printf("\n");

  pop_node(list);

  putlist(list);
  printf("\n");

}