#include "../../include/commands.h"

void	cmd_echo(t_str_arr str)
{
	int		i;
	bool	is_n_option;

	if (!str)
		return ;
	if (is_same_str(str[1], "-n"))
	{
		is_n_option = true;
		i = 2;
	}
	else
	{
		is_n_option = false;
		i = 1;
	}
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
		if (str[i])
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