/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:14:16 by nash              #+#    #+#             */
/*   Updated: 2025/02/02 19:59:49 by nash             ###   ########.fr       */
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

void	put_error(void);

bool	is_int_string(const char *s, int *num);
bool	is_sign(char c);
size_t	ft_strlen(const char *s);
bool	is_valid_arg(int argc, char **argv);
void	quick_sort(int *arr, int size);

#endif