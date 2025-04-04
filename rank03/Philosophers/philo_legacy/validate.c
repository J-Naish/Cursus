#include "philo.h"

static bool	is_numstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_empty(const char *s)
{
	if (s[0] == '\0')
		return (true);
	else
		return (false);
}

static bool	has_zero_prefix(const char *s)
{
	if (s[0] == '0')
		return (true);
	else
		return (false);
}

static bool	can_be_int(const char *s)
{
	int	i;
	int	sum;
	int	prev_sum;

	i = 0;
	sum = 0;
	prev_sum = 0;
	while (s[i])
	{
		sum = sum * 10 + (s[i] - '0');
		if (prev_sum > sum)
			return (false);
		prev_sum = sum;
		i++;
	}
	return (true);
}

bool	is_valid_arg(int argc, char **argv)
{
	int	i;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (is_empty(argv[i]) || !is_numstr(argv[i]))
			return (false);
		if (has_zero_prefix(argv[i]))
			return (false);
		if (!can_be_int(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
