/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:51:43 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 11:13:21 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	has_duplicates(int size, int *arr)
{
	int	i;

	quick_sort(arr, size);
	i = 1;
	while (i < size)
	{
		if (arr[i] == arr[i - 1])
			return (true);
		i++;
	}
	return (false);
}

bool	is_valid_arg(int argc, char **argv)
{
	int	i;
	int	*arr;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (!is_int_string(argv[i], &arr[i - 1]))
			return (free(arr), false);
		i++;
	}
	if (has_duplicates(argc - 1, arr))
		return (free(arr), false);
	return (free(arr), true);
}

// typedef struct {
//     char *description;   // Description of the test case
//     int argc;            // Argument count
//     char **argv;         // Argument vector (argv[0] is the push_swap name)
//     bool expected;       // Expected result from is_valid_arg
// } ValidArgTestCase;

// bool run_test_case(ValidArgTestCase test, int test_number)
// {
//     bool result = is_valid_arg(test.argc, test.argv);

//     if (result == test.expected)
//     {
//         printf("Test %2d Passed: %s\n", test_number, test.description);
//         return true;
//     }
//     else
//     {
//         printf("Test %2d Failed: %s\n", test_number, test.description);
//         printf("    Expected: %s, Got: %s\n",
//                test.expected ? "true" : "false",
//                result ? "true" : "false");
//         return false;
//     }
// }

// void execute_tests(ValidArgTestCase *tests, int num_tests)
// {
//     int passed = 0;

//     printf("========================================\n");
//     printf("       is_valid_arg Function Tests       \n");
//     printf("========================================\n\n");

//     for (int i = 0; i < num_tests; i++)
//     {
//         bool passed_test = run_test_case(tests[i], i + 1);
//         if (passed_test)
//             passed++;
//     }

//     printf("\n========================================\n");
//     printf("               Test Summary             \n");
//     printf("========================================\n");
//     printf("Total Test Cases : %d\n", num_tests);
//     printf("Passed           : %d\n", passed);
//     printf("Failed           : %d\n", num_tests - passed);
//     printf("========================================\n");

//     if (passed == num_tests)
//         printf("All tests passed successfully!\n");
//     else
//         printf("Some tests failed. Please review the failed cases.\n");
// }

// int main() {
//     char *desc1 = "Single valid integer argument";
//     char *desc2 = "Multiple valid integers without duplicates";
//     char *desc3 = "Multiple valid integers with duplicates";
//     char *desc4 = "Contains non-integer string";
//     char *desc5 = "Mixed valid and invalid strings";
//     char *desc6 = "All arguments are duplicates";
//     char *desc7 = "Large number of valid unique integers";
//     char *desc8 = "Negative integers without duplicates";
//     char *desc9 = "Negative integers with duplicates";
//     char *desc10 = "Arguments with leading zeros";
//     char *desc11 = "Maximum integer";
//     char *desc12 = "Minimum integer";
//     char *desc13 = "Integer exceeding INT_MAX";
//     char *desc14 = "Integer below INT_MIN";
//     char *desc15 = "Single zero argument";
// 	char *desc16 = "Space between numbers";

//     // Define test case arguments
//     char *args1[] = {"push_swap", "42"};
//     char *args2[] = {"push_swap", "1", "2", "3", "4", "5"};
//     char *args3[] = {"push_swap", "1", "2", "3", "2"};
//     char *args4[] = {"push_swap", "10", "20", "abc", "40"};
//     char *args5[] = {"push_swap", "100", "200", "xyz", "400", "500"};
//     char *args6[] = {"push_swap", "7", "7", "7", "7"};
//     char *args7[] = {"push_swap", "1000", "2000", "3000", "4000", "5000",
//                     "6000", "7000", "8000", "9000", "10000"};
//     char *args8[] = {"push_swap", "-1", "-2", "-3", "-4", "-5"};
//     char *args9[] = {"push_swap", "-10", "-20", "-10", "-40"};
//     char *args10[] = {"push_swap", "01", "02"};
//     char *args11[] = {"push_swap", "2147483647"}; // INT_MAX
//     char *args12[] = {"push_swap", "-2147483648"}; // INT_MIN
//     char *args13[] = {"push_swap", "2147483648"}; // INT_MAX + 1
//     char *args14[] = {"push_swap", "-2147483649"}; // INT_MIN - 1
//     char *args15[] = {"push_swap", "0"};
// 	char *args16[] = {"push_swap", "123", "3 4"};

// 	ValidArgTestCase test_cases[] = {
//         {desc1, 2, args1, true},
//         {desc2, 6, args2, true},
//         {desc3, 5, args3, false},
//         {desc4, 5, args4, false},
//         {desc5, 6, args5, false},
//         {desc6, 5, args6, false},
//         {desc7, 11, args7, true},
//         {desc8, 6, args8, true},
//         {desc9, 5, args9, false},
//         {desc10, 3, args10, false},
//         {desc11, 2, args11, true},
//         {desc12, 2, args12, true},
//         {desc13, 2, args13, false},
//         {desc14, 2, args14, false},
//         {desc15, 2, args15, true},
// 		{desc16, 3, args16, false}
//     };

//     int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

//     // Execute all test cases
//     execute_tests(test_cases, num_tests);

//     return 0;
// }
