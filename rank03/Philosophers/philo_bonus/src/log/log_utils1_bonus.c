#include "../philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

static size_t	ft_get_buffer(size_t n)
{
	size_t	buffer;

	buffer = 1;
	while (n >= 10)
	{
		buffer += 1;
		n /= 10;
	}
	return (buffer);
}

char	*ft_itoa(int n)
{
	size_t	buffer;
	char	*result;
	size_t	i;

	buffer = ft_get_buffer(n);
	result = (char *)malloc((buffer + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 1;
	while (i <= buffer)
	{
		if (n >= 0)
			result[buffer - i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	result[buffer] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
