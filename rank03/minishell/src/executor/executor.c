#include "../../include/executor.h"

static t_str_arr_heap	parse_prompt(t_str_heap prompt)
{
	return (ft_split(prompt, ' '));
}

void	execute_prompt(t_str_heap prompt)
{
	t_str_arr_heap	args;

	args = parse_prompt(prompt);
	if (!args)
		memory_allocation_failed();
	if (is_same_str(args[0], "exit"))
		cmd_exit(args);
}
