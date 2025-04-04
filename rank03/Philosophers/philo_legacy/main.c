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
	create_philo_threads(table);
	create_monitor_thread(table);
	join_philo_threads(table);
	join_monitor_thread(table);
	deinit_table(table);
	return (EXIT_SUCCESS);
}
