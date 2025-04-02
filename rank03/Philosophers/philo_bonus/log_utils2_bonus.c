#include "philo_bonus.h"

static void	ft_putstr(const char *s)
{
	size_t	i;

	i = ft_strlen(s);
	write(STDOUT_FILENO, s, i);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

void	log_action(t_philo philo, const char *color, const char *s)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char));
	*buffer = '\0';
	if (color)
		buffer = ft_strjoin_free(buffer, ft_strdup(color));
	buffer = ft_strjoin_free(buffer,
			ft_itoa((size_t)get_elapsed_time(philo.meta->start_time)));
	buffer = ft_strjoin_free(buffer, ft_strdup(" "));
	buffer = ft_strjoin_free(buffer, ft_itoa(philo.number));
	buffer = ft_strjoin_free(buffer, ft_strdup(" "));
	buffer = ft_strjoin_free(buffer, ft_strdup(s));
	if (color)
		buffer = ft_strjoin_free(buffer, ft_strdup(RESET));
	ft_putstr(buffer);
	free(buffer);
}
