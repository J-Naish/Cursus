#include "../include/minishell.h"

int	main(void)
{
	t_str_heap	prompt;

	prompt = readline("minishell$ ");
	if (prompt)
	{
		if (prompt && *prompt)
			add_history(prompt);
		printf("prompt is %s\n", prompt);
		free(prompt);
	}
	return (EXIT_SUCCESS);
}
