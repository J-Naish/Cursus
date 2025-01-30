/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:22:21 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 05:54:43 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	is_numeric_string(char *s)
{
	size_t	i;

	if (!s || s[0] == '\0')
		return (false);
	i = 0;
	while (s[i])
	{
		if (!is_digit((unsigned char)s[i]))
			return (false);
		i++;
	}
	return (true);
}

// int main() {
// 	// is_digitのテスト
// 	printf("Test is_digit function\n");
// 	char test_chars[] = {
// 		'a',
// 		'0',
// 		'1',
// 		'2',
// 		'3',
// 		'4',
// 		'5',
// 		'6',
// 		'7',
// 		'8',
// 		'9',
// 		'\n',
// 		'\0',
// 		'\t',
// 		13,
// 		90,
// 		127,
// 		47,
// 		48,
// 		49,
// 		50,
// 		51,
// 		52, 
// 		53,
// 		54,
// 		55,
// 		56,
// 		57,
// 		58
// 	};

// 	for (size_t i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
// 		printf("is_digit('%c' | ASCII %d) -> %s\n",
// 			(test_chars[i] >= 32 && test_chars[i] <= 126) ? test_chars[i] : ' ',
// 				test_chars[i],
// 				is_digit(test_chars[i]) ? "true" : "false");
// 	}


// 	// is_numeric_stringのテスト
// 	printf("Test is_numeric_string function\n");
// 	char *test_strings[] = {
// 		"12345",
// 		"0",
// 		"987654321",
// 		"42a",
// 		"a42",
// 		"4 2",
// 		" 123",
// 		"123 ",
// 		"",
// 		NULL,
// 		"0000",
// 		"123456789012345678901234567890",
// 		"00123",
// 		"+123",
// 		"-123",
// 	};

// 	for (size_t i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++) {
// 		printf("is_numeric_string(\"%s\") -> %s\n",
// 			test_strings[i] ? test_strings[i] : "NULL",
// 			is_numeric_string(test_strings[i]) ? "true" : "false");
// 	}

// 	return (0);
// }
