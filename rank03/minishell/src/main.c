#include "../include/minishell.h"

int	main(void)
{
	t_str_heap	prompt;

	while (1)
	{
		prompt = readline(SHELL_NAME"$ ");
		if (prompt && *prompt)
			add_history(prompt);
		execute_prompt(prompt);
		rl_on_new_line();
	}
	return (EXIT_SUCCESS);
}
