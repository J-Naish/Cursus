/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:35:29 by nash              #+#    #+#             */
/*   Updated: 2025/02/03 02:22:53 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 2)
		return (0);
	if (!is_valid_arg(argc, argv))
	{
		put_error();
		return (EXIT_SUCCESS);
	}
	list = parse(argc, argv);
	if (!list)
		return (EXIT_FAILURE);
	putlist_as_stack(list);
	return (EXIT_SUCCESS);
}
