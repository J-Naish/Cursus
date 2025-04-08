#include "../include/minishell.h"

int	main(void)
{
	t_str_heap	input;

	input = readline("minishell$ ");
	if (input)
	{
		printf("input is %s\n", input);
		free(input);
	}
	return (EXIT_SUCCESS);
}
