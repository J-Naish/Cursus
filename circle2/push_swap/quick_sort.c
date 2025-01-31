/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nash <nash@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:26:52 by nash              #+#    #+#             */
/*   Updated: 2025/01/31 10:40:46 by nash             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1)
			i++;
		while (arr[j] > pivot && j >= low + 1)
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[low], &arr[j]);
	return (j);
}

static void	quick_sort_recursive(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort_recursive(arr, low, pivot_index - 1);
		quick_sort_recursive(arr, pivot_index + 1, high);
	}
}

void	quick_sort(int *arr, int size)
{
	if (size <= 1)
		return ;
	quick_sort_recursive(arr, 0, size - 1);
}

// static void print_array(int *arr, int size, const char *message)
// {
//     printf("%s\n", message);
//     if (size == 0) {
//         printf("Array is empty.\n");
//         return;
//     }
//     for(int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
// 	int arr1[] = {34, 7, 23, 32, 5, 62, 32, 7, 89, 0, -5, 23};
//     int size1 = sizeof(arr1) / sizeof(arr1[0]);

//     print_array(arr1, size1,
// 		"Test Case 1 - Before sorting:");
//     quick_sort(arr1, size1);
//     print_array(arr1, size1, "Test Case 1 - After sorting:");

//     // Test Case 2: Already sorted array
//     int arr2[] = {-10, -5, 0, 5, 10, 15, 20};
//     int size2 = sizeof(arr2) / sizeof(arr2[0]);

//     print_array(arr2, size2,
// 		"\nTest Case 2 - Before sorting:");
//     quick_sort(arr2, size2);
//     print_array(arr2, size2, "Test Case 2 - After sorting:");

//     // Test Case 3: Reverse sorted array
//     int arr3[] = {100, 90, 80, 70, 60, 50, 40};
//     int size3 = sizeof(arr3) / sizeof(arr3[0]);

//     print_array(arr3, size3,
// 		"\nTest Case 3 - Before sorting:");
//     quick_sort(arr3, size3);
//     print_array(arr3, size3, "Test Case 3 - After sorting:");

//     // Test Case 4: Array with all identical elements
//     int arr4[] = {5, 5, 5, 5, 5, 5, 5};
//     int size4 = sizeof(arr4) / sizeof(arr4[0]);

//     print_array(arr4, size4,
// 		"\nTest Case 4 - Before sorting:");
//     quick_sort(arr4, size4);
//     print_array(arr4, size4, "Test Case 4 - After sorting:");

//     // Test Case 5: Empty array
//     int arr5[] = {};
//     int size5 = sizeof(arr5) / sizeof(arr5[0]);

//     print_array(arr5, size5,
// 		"\nTest Case 5 - Before sorting:");
//     quick_sort(arr5, size5);
//     print_array(arr5, size5, "Test Case 5 - After sorting:");

//     // Test Case 6: Single-element array
//     int arr6[] = {42};
//     int size6 = sizeof(arr6) / sizeof(arr6[0]);

//     print_array(arr6, size6,
// 		"\nTest Case 6 - Before sorting:");
//     quick_sort(arr6, size6);
//     print_array(arr6, size6,
// 		"Test Case 6 - After sorting:");

//     // Test Case 7: Large array
//     int size7 = 1000;
//     int arr7[size7];
//     for(int i = 0; i < size7; i++) {
//         arr7[i] = rand() % 2001 - 1000;
//     }

//     print_array(arr7, size7,
// 		"\nTest Case 7 - Before sorting:");
//     quick_sort(arr7, size7);
//     print_array(arr7, size7,
// 		"Test Case 7 - After sorting:");

//     // Test Case 8: Array with maximum and minimum integers
//     int arr8[] = {INT32_MAX, INT32_MIN, 0, -1, 1, INT32_MAX, INT32_MIN};
//     int size8 = sizeof(arr8) / sizeof(arr8[0]);

//   print_array(arr8, size8,
//     "\nTest Case 8 - Before sorting:");
//     quick_sort(arr8, size8);
//     print_array(arr8, size8, "Test Case 8 - After sorting:");

//     // Test Case 9: Array with alternating high and low values
//     int arr9[] = {1, 100, 2, 99, 3, 98, 4, 97, 5, 96};
//     int size9 = sizeof(arr9) / sizeof(arr9[0]);

//     print_array(arr9, size9,
// 		"\nTest Case 9 - Before sorting:");
//     quick_sort(arr9, size9);
//     print_array(arr9, size9,
// 		"Test Case 9 - After sorting:");

//     // Test Case 10: Array with prime numbers
//     int arr10[] = {29, 3, 17, 2, 23, 5, 11, 7, 13, 19};
//     int size10 = sizeof(arr10) / sizeof(arr10[0]);

//     print_array(arr10, size10,
// 		"\nTest Case 10 - Before sorting:");
//     quick_sort(arr10, size10);
//     print_array(arr10, size10, "Test Case 10 - After sorting:");

//     // Test Case 11: Array with powers of two
//     int arr11[] = {16, 2, 8, 4, 1, 32, 64, 128, 256, 512};
//     int size11 = sizeof(arr11) / sizeof(arr11[0]);

//     print_array(arr11, size11,
// 		"\nTest Case 11 - Before sorting:");
//     quick_sort(arr11, size11);
//     print_array(arr11, size11, "Test Case 11 - After sorting:");

//     // Test Case 12: Array with sequential repeats
//     int arr12[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
//     int size12 = sizeof(arr12) / sizeof(arr12[0]);

//     print_array(arr12, size12,
// 		"\nTest Case 12 - Before sorting:");
//     quick_sort(arr12, size12);
//     print_array(arr12, size12, "Test Case 12 - After sorting:");

//     // Test Case 13: Array with multiple duplicates
//     int arr13[] = {10, -1, 2, -1, 10, 2, 2, -1, 10, 10};
//     int size13 = sizeof(arr13) / sizeof(arr13[0]);

//     print_array(arr13, size13,
// 		"\nTest Case 13 - Before sorting:");
//     quick_sort(arr13, size13);
//     print_array(arr13, size13, "Test Case 13 - After sorting:");

//     // Test Case 14: Array with negative and positive numbers
//     int arr14[] = {-3, 14, -1, 0, -7, 8, 5, -2, 9, -6};
//     int size14 = sizeof(arr14) / sizeof(arr14[0]);

//     print_array(arr14, size14,
// 		"\nTest Case 14 - Before sorting:");
//     quick_sort(arr14, size14);
//     print_array(arr14, size14, "Test Case 14 - After sorting:");

// 	return 0;
// }
