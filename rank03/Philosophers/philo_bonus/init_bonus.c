#include "philo_bonus.h"

static size_t	convert_to_sizet(const char *s)
{
	size_t	result;
	int		i;

	result = 0;
	i = 0;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}

static t_config	init_config(int argc, char **argv)
{
	t_config	config;

	config.num_philos = convert_to_sizet(argv[1]);
	config.time_to_die = convert_to_sizet(argv[2]);
	config.time_to_eat = convert_to_sizet(argv[3]);
	config.time_to_sleep = convert_to_sizet(argv[4]);
	if (argc == 6)
		config.times_to_eat_to_exit = convert_to_sizet(argv[5]);
	else
		config.times_to_eat_to_exit = SIZE_MAX;
	return (config);
}

static t_philo	init_philo(size_t number)
{
	t_philo	philo;

	philo.number = number;
	philo.state = THINKING;
	philo.eating_count = 0;
	gettimeofday(&(philo.last_meal_time), NULL);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;
	size_t	i;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->config = init_config(argc, argv);
	gettimeofday(&(table->start_time), NULL);
	table->philos
		= (t_philo *)malloc(sizeof(t_philo) * table->config.num_philos);
	if (!table->philos)
		return (free(table), NULL);
	i = 0;
	while (i < table->config.num_philos)
	{
		table->philos[i] = init_philo(i + 1);
		i++;
	}
	table->sem_forks
		= sem_open("/forks", O_CREAT, 0644, table->config.num_philos);
	if (table->sem_forks == SEM_FAILED)
		return (free(table), free(table->philos), NULL);
	return (table);
}
