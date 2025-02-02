/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:35:29 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 04:01:38 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort1(void)
{
	exit(EXIT_SUCCESS);
}

void	sort2(char **argv)
{
	if (atoi_strict(argv[1]) > atoi_strict(argv[2]))
		ft_putstr("sa\n");
	exit(EXIT_SUCCESS);
}

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
		sort1();
	else if (argc == 3)
		sort2(argv);
	stack_a = parse(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	stack_b = create_list();
	if (!stack_b)
		return (EXIT_FAILURE);
	putlist_as_stack(stack_a);
	return (EXIT_SUCCESS);
}
