#include "../../include/cub3d.h"

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
}

char	**calloc_strarr(size_t size)
{
	size_t	i;
	char	**lines;

	lines = (char **)malloc((size + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		lines[i] = NULL;
		i++;
	}
	return (lines);
}

size_t	strarr_length(char **strarr)
{
	size_t	length;

	if (!strarr)
		return (0);
	length = 0;
	while (strarr[length])
		length++;
	return (length);
}
