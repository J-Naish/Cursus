#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!is_valid_arg(argc, argv))
	{
		write(STDERR_FILENO, "Invalid args\n", 13);
		return (EXIT_FAILURE);
	}
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	deinit_table(table);
	return (0);
}
