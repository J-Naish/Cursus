#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	if (!is_valid_arg(argc, argv))
	{
		write(STDERR_FILENO, "Invalid args\n", 13);
		return (EXIT_FAILURE);
	}
	return (0);
}
