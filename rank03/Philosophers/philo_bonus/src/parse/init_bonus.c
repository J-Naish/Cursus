#include "../philo_bonus.h"

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

static t_meta	*init_sems(t_meta *meta)
{
	meta->sem_name_forks = "/forks";
	meta->sem_name_log = "/log";
	meta->sem_name_meals = "/meals";
	meta->sem_name_death = "/death";
	sem_unlink(meta->sem_name_forks);
	sem_unlink(meta->sem_name_log);
	sem_unlink(meta->sem_name_meals);
	sem_unlink(meta->sem_name_death);
	meta->sem_forks = sem_open(meta->sem_name_forks,
			O_CREAT, 0644, meta->config.num_philos);
	meta->sem_log = sem_open(meta->sem_name_log,
			O_CREAT, 0644, 1);
	meta->sem_meals = sem_open(meta->sem_name_meals,
			O_CREAT, 0644, 0);
	meta->sem_death = sem_open(meta->sem_name_death,
			O_CREAT, 0644, 1);
	return (meta);
}

static t_meta	*init_meta(int argc, char **argv)
{
	t_meta	*meta;

	meta = (t_meta *)malloc(sizeof(t_meta));
	if (!meta)
		return (NULL);
	meta->config = init_config(argc, argv);
	meta->sem_name_forks = "/forks";
	meta->sem_forks = sem_open(meta->sem_name_forks,
			O_CREAT, 0644, meta->config.num_philos);
	meta = init_sems(meta);
	if (!meta)
		return (NULL);
	meta->start_time = get_current_time();
	return (meta);
}

static t_philo	init_philo(size_t index, t_meta *meta)
{
	t_philo	philo;

	philo.number = index + 1;
	philo.state = THINKING;
	philo.eating_count = 0;
	philo.last_meal_time = get_current_time();
	philo.meta = meta;
	return (philo);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;
	size_t	i;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->meta = init_meta(argc, argv);
	if (!table->meta)
		return (free(table), NULL);
	table->philos
		= (t_philo *)malloc(sizeof(t_philo) * table->meta->config.num_philos);
	if (!table->philos)
		return (free(table->meta), free(table), NULL);
	i = 0;
	while (i < table->meta->config.num_philos)
	{
		table->philos[i] = init_philo(i, table->meta);
		i++;
	}
	return (table);
}
