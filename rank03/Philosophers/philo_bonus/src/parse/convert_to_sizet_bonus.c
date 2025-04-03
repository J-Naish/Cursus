#include "../philo_bonus.h"

size_t	convert_to_sizet(const char *s)
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
