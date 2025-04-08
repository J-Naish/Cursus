#include "../../include/builtins.h"

// クォートまで出力されてる
void	cmd_echo(t_command *command)
{
	int		i;
	bool	is_n_option;

	if (is_same_str(command->args[1], "-n"))
	{
		is_n_option = true;
		i = 2;
	}
	else
	{
		is_n_option = false;
		i = 1;
	}
	while (command->args[i])
	{
		printf("%s", command->args[i]);
		i++;
		if (command->args[i])
			printf(" ");
	}
	if (!is_n_option)
		printf("\n");
}

// int main() {
// 	char *test1[] = {
// 		"echo"
// 		"lorem",
// 		"ipsum",
// 		"dollar",
// 		"sit",
// 		"ammet",
// 		NULL
// 	};
// 	cmd_echo(test1);
// 	cmd_echo(test1);
// 	char *test2[] = {
// 		NULL
// 	};
// 	cmd_echo(test2);
// 	cmd_echo(test2);
// }