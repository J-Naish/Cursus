/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:35:29 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 05:45:54 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	if (!is_valid_arg(argc, argv))
	{
		put_error();
		return (0);
	}
	if (argc == 2)
		exit(0);
	stack_a = parse(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	stack_b = init_list();
	if (!stack_b)
		return (free(stack_a), EXIT_FAILURE);
	normalize_list(stack_a);
	if (argc <= 5)
		sort_sm(stack_a, stack_b, argc - 1);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
