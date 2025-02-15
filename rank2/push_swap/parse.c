/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:27:20 by nash              #+#    #+#             */
/*   Updated: 2025/02/16 07:19:22 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_strict(const char *s)
{
	size_t	i;
	int		result;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 - (s[i] - '0');
		i++;
	}
	return (result * (-1 * sign));
}

t_stack	*parse(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc < 2)
		return (NULL);
	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		append_node(stack, atoi_strict(argv[i]));
		i++;
	}
	return (stack);
}

// void testAtoiStrict(const char *s) {
//   int result = atoi_strict(s);
//   int expected = atoi(s);
//   if (result != expected) {
// 	fprintf(stderr, "❌️%s: Fails\n", s);
//   } else {
// 	fprintf(stdout, "✅️%s: OK\n", s);
//   }
// }
// int main() {
//   printf("=== atoi_strict 関数のテスト ===\n\n");
//   // 入力値が正しいことを保証してから呼ばれるので
//   // 有効なint型のみテスト
//   testAtoiStrict("42");
//   testAtoiStrict("0");
//   testAtoiStrict("-42");
//   testAtoiStrict("12345");
//   testAtoiStrict("-98765");
//   testAtoiStrict("2147483647");
//   testAtoiStrict("-2147483648");

//   char* testArgv[] = {
// 	"./push_swap",
// 	"42", "0", "-42", "12345", "-98765",
// 	"2147483647", "-2147483648"
//   };

//   t_stack* stack = parse(8, testArgv);
//   putstack(stack);

//   return 0;
// }