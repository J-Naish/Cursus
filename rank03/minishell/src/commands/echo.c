#include "../../include/commands.h"

void	cmd_echo(t_str_arr str, t_echo_option option)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
		if (str[i])
			printf(" ");
	}
	if (option != N)
		printf("\n");
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
// 	cmd_echo(test1, N);
// 	cmd_echo(test1, NONE);
// 	char *test2[] = {
// 		NULL
// 	};
// 	cmd_echo(test2, N);
// 	cmd_echo(test2, NONE);
// }