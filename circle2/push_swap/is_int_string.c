/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:22:21 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 07:25:43 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

static bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	else
		return (false);
}

static bool	is_numeric_string(const char *s)
{
	size_t	i;

	if (!s || !s[0])
		return (false);
	i = 0;
	if (is_sign(s[i]))
		i++;
	if (!s[i])
		return (false);
	while (s[i])
	{
		if (!ft_is_digit((unsigned char)s[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	has_invalid_zero(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (is_sign(s[0]))
	{
		if (len > 2 && s[1] == '0')
			return (true);
	}
	else
	{
		if (len > 1 && s[0] == '0')
			return (true);
	}
	return (false);
}

bool	is_int_string(const char *s)
{
	size_t		i;
	long long	value;
	int			sign;

	if (!is_numeric_string(s) || has_invalid_zero(s))
		return (false);
	value = 0;
	sign = 1;
	i = 0;
	if (is_sign(s[i]))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		value = value * 10 + (s[i] - '0');
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && (-value) < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}

// int main() {

// 	printf("=== Test is_int_string Function ===\n\n");

//     // テストケース
//     char *test_cases[] = {
//         // 有効な入力
//         "0",
//         "123",
//         "-456",
//         "+789",
//         "2147483647",
//         "-2147483648",

//         // 無効な入力(文字が含まれる)
//         "12a3",
//         "++123",
//         "123-",
//         "12 3",
//         "1.23",
//         "abc",
//         "123abc",
//         "abc123",
//         "12+3",
//         "123+",
//         "+-123",
//         "--123",

//         // 先頭の0️
//         "00",
//         "0123",
//         "-0123",
//         "+0123",

//         // オーバーフロー・アンダーフロー
//         "2147483648",
//         "-2147483649",
//         "9999999999",
//         "-9999999999",

//         // エッジケース
//         "",
//         NULL,
//         " ",
//         "\t",
//         "\n",
//         "   ",
//         "+",
//         "-",
//         "+0",
//         "-0",
//         "0000",
//         "+000",
//         "-000",

//         // 最大値・最小値付近の値
//         "2147483646",
//         "-2147483647",
//     };

//     size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

//     for (size_t i = 0; i < num_tests; i++) {
//         char *s = test_cases[i];
//         char display[100];
//         if (s == NULL) {
//             snprintf(display, sizeof(display), "NULL");
//         } else if (s[0] == '\0') {
//             snprintf(display, sizeof(display), "\"\"");
//         } else {
//             bool printable = true;
//             for (size_t j = 0; s[j] != '\0'; j++) {
//                 if (s[j] < 32 || s[j] > 126) {
//                     printable = false;
//                     break;
//                 }
//             }
//             if (printable) {
//                 snprintf(display, sizeof(display), "\"%s\"", s);
//             } else {
//                 snprintf(display, sizeof(display), "Non-printable");
//             }
//         }

//         bool result = is_int_string(s);
//         printf("is_int_string(%s) -> %s\n",
//                display,
//                result ? "true" : "false");
//     }

// 	return (0);
// }

/*
# DOCS
先頭が＋あるいはーで始まる
数字のみで構成されるか判別する関数
先頭の0は無効のものとみなす

NULLガードはis_numeric_stringで行う
*/