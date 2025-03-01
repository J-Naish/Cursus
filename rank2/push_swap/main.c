/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:35:29 by nash              #+#    #+#             */
/*   Updated: 2025/03/01 19:58:27 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!is_valid_arg(argc, argv))
	{
		put_error();
		exit(EXIT_FAILURE);
	}
	stack_a = parse(argc, argv);
	normalize_stack(stack_a);
	stack_b = init_stack();
	if (!stack_b)
		return (free(stack_a), EXIT_FAILURE);
	exit_if_sorted(stack_a, stack_b);
	if (argc <= 6)
		sort_sm(stack_a, stack_b, argc - 1);
	else
		sort_lg(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
