/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:35:29 by nash              #+#    #+#             */
/*   Updated: 2025/02/28 20:05:39 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_arg(int argc, char **argv)
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!is_valid_arg(argc, argv))
	{
		put_error();
		exit(EXIT_FAILURE);
	}
}

static char	**split_arg(char **argv)
{
	char	**separated;
	char	**result;
	int		i;

	separated = ft_split(argv[1], ' ');
	if (!separated)
		return (NULL);
	i = 0;
	while (separated[i])
		i++;
	result = (char **)malloc(sizeof(char *) * (i + 2));
	if (!result)
		return (free_strarr(separated), NULL);
	result[0] = ft_strdup("./push_swap");
	if (!result[0])
		return (free_strarr(separated), free(result), NULL);
	i = 0;
	while (separated[i])
	{
		result[1 + i] = ft_strdup(separated[i]);
		i++;
	}
	result[1 + i] = NULL;
	free_strarr(separated);
	return (result);
}

static int	get_arg_count(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}

static void	free_all(t_stack *a, t_stack *b, int argc, char **numbers)
{
	free_stack(a);
	free_stack(b);
	if (argc == 2)
		free_strarr(numbers);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int		arg_count;

	numbers = argv;
	arg_count = argc;
	if (argc == 2)
	{
		numbers = split_arg(argv);
		arg_count = get_arg_count(numbers);
	}
	check_arg(arg_count, numbers);
	stack_a = parse(arg_count, numbers);
	normalize_stack(stack_a);
	stack_b = init_stack();
	if (!stack_b)
		return (free(stack_a), EXIT_FAILURE);
	exit_if_sorted(stack_a, stack_b);
	if (arg_count <= 6)
		sort_sm(stack_a, stack_b, arg_count - 1);
	else
		sort_lg(stack_a, stack_b);
	free_all(stack_a, stack_b, argc, numbers);
	return (0);
}
