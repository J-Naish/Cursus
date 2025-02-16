/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:14:16 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 19:55:10 by nash             ###   ########.fr       */
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

typedef struct t_stack
{
	t_node	*sentinel;
}	t_stack;

t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
int		get_stack_size(t_stack *stack);
bool	is_empty(t_stack *stack);
bool	is_singleton(t_stack *stack);

void	prepend_node(t_stack *stack, int value);
void	append_node(t_stack *stack, int value);
void	shift_node(t_stack *stack);
void	pop_node(t_stack *stack);

void	normalize_stack(t_stack *stack);

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(const char *s);

void	putnode(t_node *node);
void	putstack(t_stack *stack);
t_stack	*create_test_stack(void);

void	put_error(void);

void	swap_put(t_stack *stack, char stack_name);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	rotate_put(t_stack *stack, char stack_name);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rrotate_put(t_stack *stack, char stack_name);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

bool	is_int_string(const char *s, int *num);
void	quick_sort(int *arr, int size);
bool	is_valid_arg(int argc, char **argv);
t_stack	*parse(int argc, char **argv);

void	move_min_to_top(t_stack *stack, char stack_name);
void	sort3(t_stack *stack, char stack_name);
void	sort_sm(t_stack *stack_a, t_stack *stack_b, int size);

int		find_index(t_stack *stack, t_node *node);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_index_of_max(t_stack *stack);
int		find_index_of_min(t_stack *stack);

int		calculate_cost(int index, int size);
int		total_cost(int cost_a, int cost_b);
int		find_insert_position_in_b(t_stack *b, int value);

void	sort_lg(t_stack *stack_a, t_stack *stack_b);

#endif