#include "../../include/minishell.h"

static int	get_square(int x)
{
	return (x * x);
}

int	example(int x)
{
	return (get_square(x) + 42);
}

// // テストコード例
// #include <stdio.h>
// int main() {
// 	printf("%d\n", example(10));
// 	printf("%d\n", example(0));
// 	printf("%d\n", example(-1));
// 	printf("%d\n", example(1234));
// 	printf("%d\n", example(-567));
// }
