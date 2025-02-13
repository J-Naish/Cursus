/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:35:29 by nash              #+#    #+#             */
/*   Updated: 2025/02/14 04:43:44 by nash             ###   ########.fr       */
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
		return (EXIT_SUCCESS);
	}
	if (argc == 2)
		exit(EXIT_SUCCESS);
	stack_a = parse(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	stack_b = init_list();
	if (!stack_b)
		return (EXIT_FAILURE);
	if (argc <= 6)
		sort_sm(stack_a, stack_b, argc - 1);
	free_list(stack_a);
	free_list(stack_b);
	return (EXIT_SUCCESS);
}
