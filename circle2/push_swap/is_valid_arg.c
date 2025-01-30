/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:51:43 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 08:34:39 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	has_duplicate(int size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid_arg(int argc, char **argv)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(argc * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		if (!is_int_string(argv[i]))
			return (false);
		arr[i] = atoi_strict(argv[i]);
		i++;
	}
	if (has_duplicate(argc, arr))
		return (free(arr), false);
	free(arr);
	return (true);
}

// int main() {
//     printf("=== has_duplicate 関数のテスト ===\n\n");

//     typedef struct {
//         int size;
//         int *arr;
//         bool expected;
//     } DuplicateTest;

//     // Define test arrays
//     int arr1[] = {};
//     int arr2[] = {1};
//     int arr3[] = {1, 2, 3, 4, 5};
//     int arr4[] = {1, 2, 3, 2};
//     int arr5[] = {5, 5, 5, 5, 5};
//     int arr6[] = {-1, -2, -3, -4, -1};
//     int arr7[] = {0, 0};
//     int arr8[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
//     int arr9[] = {1, 2, 3, 4, 5, 1};

//     // Define test cases
//     DuplicateTest duptest[] = {
//         {0, arr1, false},
//         {1, arr2, false},
//         {5, arr3, false},
//         {4, arr4, true},
//         {5, arr5, true},
//         {5, arr6, true},
//         {2, arr7, true},
//         {9, arr8, false},
//         {6, arr9, true},
//     };

//     int num_tests = sizeof(duptest) / sizeof(duptest[0]);
//     int passed = 0;

//     for (int i = 0; i < num_tests; i++) {
//         DuplicateTest tc = duptest[i];
//         bool actual = has_duplicate(tc.size, tc.arr);
//         bool expected = tc.expected;

//         if (actual == expected) {
//             printf("Test %d: has_duplicate(", i + 1);
//             printf("size=%d, arr={", tc.size);
//             for (int j = 0; j < tc.size; j++) {
//                 printf("%d", tc.arr[j]);
//                 if (j < tc.size - 1)
//                     printf(", ");
//             }
//             printf("}) = %s [OK]\n", actual ? "true" : "false");
//             passed++;
//         } else {
//             printf("Test %d: has_duplicate(", i + 1);
//             printf("size=%d, arr={", tc.size);
//             for (int j = 0; j < tc.size; j++) {
//                 printf("%d", tc.arr[j]);
//                 if (j < tc.size - 1)
//                     printf(", ");
//             }
//             printf("}) = %s [FAIL] (Expected: %s)\n",
//                    actual ? "true" : "false",
//                    expected ? "true" : "false");
//         }
//     }

//     printf("\n=== テスト結果 ===\n");
//     printf("合計テストケース: %d\n", num_tests);
//     printf("成功したテストケース: %d\n", passed);
//     printf("失敗したテストケース: %d\n", num_tests - passed);

// 	printf("=== is_valid_arg 関数のテスト ===\n\n");

//     typedef struct {
//         int argc;
//         char **argv;
//         bool expected;
//         char *description;
//     } ValidArgTest;

//     // Define test case descriptions
//     char *desc1 = "No arguments";
//     char *desc2 = "Single valid integer argument";
//     char *desc3 = "Multiple valid integers without duplicates";
//     char *desc4 = "Multiple valid integers with duplicates";
//     char *desc5 = "Contains non-integer string";
//     char *desc6 = "Mixed valid and invalid strings";
//     char *desc7 = "All arguments are duplicates";
//     char *desc8 = "Large number of valid unique integers";
//     char *desc9 = "Negative integers without duplicates";
//     char *desc10 = "Negative integers with duplicates";

//     // Define test case arguments
//     char *args1[] = {};
//     char *args2[] = {"42"};
//     char *args3[] = {"1", "2", "3", "4", "5"};
//     char *args4[] = {"1", "2", "3", "2"};
//     char *args5[] = {"10", "20", "abc", "40"};
//     char *args6[] = {"100", "200", "xyz", "400", "500"};
//     char *args7[] = {"7", "7", "7", "7"};
//     char *args8[] = {"1000", "2000", "3000", "4000", "5000",
// 					"6000", "7000", "8000", "9000", "10000"};
//     char *args9[] = {"-1", "-2", "-3", "-4", "-5"};
//     char *args10[] = {"-10", "-20", "-10", "-40"};

//     // Define test cases
//     ValidArgTest test_cases[] = {
//         {0, args1, true, desc1},
//         {1, args2, true, desc2},
//         {5, args3, true, desc3},
//         {4, args4, false, desc4},
//         {4, args5, false, desc5},
//         {5, args6, false, desc6},
//         {4, args7, false, desc7},
//         {10, args8, true, desc8},
//         {5, args9, true, desc9},
//         {4, args10, false, desc10},
//     };

//     int numtest_arg = sizeof(test_cases) / sizeof(test_cases[0]);
//     int passed_arg = 0;

//     for (int i = 0; i < numtest_arg; i++) {
//         ValidArgTest tc = test_cases[i];
//         bool actual = is_valid_arg(tc.argc, tc.argv);
//         bool expected = tc.expected;

//         if (actual == expected) {
//             printf("Test %d: %s [OK]\n", i + 1, tc.description);
//             passed_arg++;
//         } else {
//             printf("Test %d: %s [FAIL] (Expected: %s, Got: %s)\n",
//                    i + 1,
//                    tc.description,
//                    expected ? "true" : "false",
//                    actual ? "true" : "false");
//         }
//     }

//     printf("\n=== テスト結果 ===\n");
//     printf("合計テストケース: %d\n", numtest_arg);
//     printf("成功したテストケース: %d\n", passed_arg);
//     printf("失敗したテストケース: %d\n", numtest_arg - passed_arg);

//     return 0;
// }

/*
DOCS
無効
引数がintで表せない
ダブりがある
*/