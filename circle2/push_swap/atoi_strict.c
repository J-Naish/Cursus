/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:27:14 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 07:44:11 by nash             ###   ########.fr       */
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
	if (is_sign(s[i]))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

// int main() {
//   printf("=== atoi_strict 関数のテスト ===\n\n");

//   typedef struct {
//     const char	*input;
//     int			expected;
//   } TestCase;

//   // テストケースの定義
//   TestCase test_cases[] = {
//   // 有効な整数文字列
//     {"0", 0},
//     {"123", 123},
//     {"-456", -456},
//     {"+789", 789},
//     {"2147483647", 2147483647},     // INT_MAX
//     {"-2147483648", -2147483648},   // INT_MIN
//     {"2147483646", 2147483646},     // INT_MAX - 1
//     {"-2147483647", -2147483647},   // INT_MIN + 1
//   };

//   int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
//   int passed = 0;

//   for (int i = 0; i < num_tests; i++) {
//     const char *input = test_cases[i].input;
//     int expected = test_cases[i].expected;
//     int actual = atoi_strict(input);

//     // テスト結果の比較
//     if (actual == expected) {
//       printf("Test %d: atoi_strict(\"%s\") = %d [OK]\n",
//         i + 1, input, actual);
//         passed++;
//     } else {
//       printf("Test %d: atoi_strict(\"%s\") = %d [FAIL] (Expected: %d)\n",
//         i + 1, input, actual, expected);
//     }
//   }

//   printf("\n=== テスト結果 ===\n");
//   printf("合計テストケース: %d\n", num_tests);
//   printf("成功したテストケース: %d\n", passed);
//   printf("失敗したテストケース: %d\n", num_tests - passed);

//   return 0;
// }

// /*
// DOCS
// is_int_stringで有効な文字か判別した後に用いられる
// なのでエッジケースのハンドリングやオーバーフロー等は気にしない
// */