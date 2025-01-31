/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:14:16 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 11:10:47 by nash             ###   ########.fr       */
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
	int				data;
	struct t_node	*next;
}	t_node;

void	put_error(void);
bool	is_int_string(const char *s, int *num);
bool	is_sign(char c);
size_t	ft_strlen(const char *s);
int		atoi_strict(const char *s);
bool	is_valid_arg(int argc, char **argv);
void	quick_sort(int *arr, int size);

#endif