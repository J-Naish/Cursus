/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:14:16 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 01:35:09 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>

# include <stdio.h>

typedef struct t_node
{
	int				value;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

typedef struct t_list
{
	t_node	*sentinel;
}	t_list;

t_list	*create_list(void);
void	insert_node(t_node *node, int value);
void	append_node(t_list *list, int value);
void	remove_node(t_node *node);
void	pop_node(t_list *list);

void	putnode(t_node *node);
void	putlist(t_list *list);
void	putlist_as_stack(t_list *list);
t_list	*create_test_list(void);

void	put_error(void);

void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *list_a, t_list *list_b);

void	pa(t_list *list_a, t_list *list_b);
void	pb(t_list *list_a, t_list *list_b);

bool	is_int_string(const char *s, int *num);
bool	is_sign(char c);

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(const char *s);

bool	is_valid_arg(int argc, char **argv);
void	quick_sort(int *arr, int size);

#endif