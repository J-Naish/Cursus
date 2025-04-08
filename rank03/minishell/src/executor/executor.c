#include "../../include/executor.h"

static t_command	*parse_prompt(t_str_heap prompt)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
	{
		free(prompt);
		memory_allocation_failed();
	}
	command->raw_prompt = prompt;
	command->args = ft_split(prompt, ' ');
	if (!command->args)
	{
		free(prompt);
		memory_allocation_failed();
	}
	return (command);
}

void	execute_prompt(t_str_heap prompt)
{
	t_command	*command;

	command = parse_prompt(prompt);
	if (is_same_str(command->args[0], "exit"))
		cmd_exit(command);
	else if (is_same_str(command->args[0], "echo"))
	{
		cmd_echo(command);
		free_command(command);
	}
	else
	{
		free_command(command);
	}
}
