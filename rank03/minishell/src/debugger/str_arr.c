/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:52:39 by nash              #+#    #+#             */
/*   Updated: 2025/06/21 18:52:39 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/debugger.h"

void	print_str_arr(const t_str_arr str_arr)
{
	int	i;

	i = 0;
	if (!str_arr)
	{
		ft_putstr_fd(BOLD"null\n"RESET, STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("[ ", STDOUT_FILENO);
	while (str_arr[i])
	{
		print_str(str_arr[i]);
		ft_putstr_fd(", ", STDOUT_FILENO);
		i++;
	}
	print_str(str_arr[i]);
	ft_putstr_fd(" ]", STDOUT_FILENO);
}

// int main() {
// 	char *test1[] = {
// 		"lorem",
// 		"ipsum",
// 		"dollar",
// 		"sit",
// 		"ammet",
// 		NULL
// 	};
// 	print_str_arr(test1);
// 	char *test2[] = {
// 		"",
// 		"  gdsgs ",
// 		"	",
// 		"ds\nggddsf"
// 	};
// 	print_str_arr(test2);
// 	char *test3[] = {
// 		NULL
// 	};
// 	print_str_arr(test3);
// 	char **test4 = NULL;
// 	print_str_arr(test4);
// }