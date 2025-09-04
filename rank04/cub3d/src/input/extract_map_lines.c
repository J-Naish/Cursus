#include "../../include/cub3d.h"

static size_t	count_map_lines(char **lines)
{
	size_t	count;
	bool	map_found;
	int		i;

	count = 0;
	i = 0;
	map_found = false;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
			map_found = true;
		if (map_found)
			count++;
		i++;
	}
	return (count);
}

char	**extract_map_lines(char **lines)
{
	char	**map_lines;
	int		i;
	int		j;
	bool	map_found;

	map_lines = calloc_strarr(count_map_lines(lines));
	if (!map_lines)
		return (NULL);
	i = 0;
	j = 0;
	map_found = false;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
			map_found = true;
		if (map_found)
		{
			map_lines[j] = ft_strdup(lines[i]);
			if (!map_lines[j])
				return (free_strarr(map_lines), NULL);
			j++;
		}
		i++;
	}
	return (map_lines);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
// 	printf("=== Testing Extract Map Lines ===\n");
// 	char **lines;
// 	char **map_lines;
// 	int fd;
// 	int i;
// 	// Test 1: Simple map
// 	printf("Test 1: Extracting from simple.cub...\n");
// 	fd = open("maps/valid/simple.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open simple.cub\n");
// 		return (1);
// 	}
// 	lines = get_lines(fd);
// 	close(fd);
// 	if (!lines) {
// 		printf("Failed to read lines\n");
// 		return (1);
// 	}
// 	map_lines = extract_map_lines(lines);
// 	printf("Original lines:\n");
// 	i = 0;
// 	while (lines[i]) {
// 		printf("  [%d]: '%s'\n", i, lines[i]);
// 		i++;
// 	}
// 	printf("Extracted map lines:\n");
// 	if (map_lines) {
// 		i = 0;
// 		while (map_lines[i]) {
// 			printf("  [%d]: '%s'\n", i, map_lines[i]);
// 			i++;
// 		}
// 		free_strarr(map_lines);
// 	} else {
// 		printf("  (NULL - extraction failed)\n");
// 	}
// 	free_strarr(lines);
// 	// Test 2: Map with empty lines
// 	printf("\nTest 2: Extracting from empty_lines.cub...\n");
// 	fd = open("maps/valid/empty_lines.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open empty_lines.cub\n");
// 		return (1);
// 	}
// 	lines = get_lines(fd);
// 	close(fd);
// 	map_lines = extract_map_lines(lines);
// 	printf("Original lines:\n");
// 	i = 0;
// 	while (lines[i]) {
// 		printf("  [%d]: '%s'\n", i, lines[i]);
// 		i++;
// 	}
// 	printf("Extracted map lines:\n");
// 	if (map_lines) {
// 		i = 0;
// 		while (map_lines[i]) {
// 			printf("  [%d]: '%s'\n", i, map_lines[i]);
// 			i++;
// 		}
// 		free_strarr(map_lines);
// 	} else {
// 		printf("  (NULL - extraction failed)\n");
// 	}
// 	free_strarr(lines);
// 	// Test 3: Map with spaces
// 	printf("\nTest 3: Extracting from with_spaces.cub...\n");
// 	fd = open("maps/valid/with_spaces.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open with_spaces.cub\n");
// 		return (1);
// 	}
// 	lines = get_lines(fd);
// 	close(fd);
// 	map_lines = extract_map_lines(lines);
// 	printf("Original lines:\n");
// 	i = 0;
// 	while (lines[i]) {
// 		printf("  [%d]: '%s'\n", i, lines[i]);
// 		i++;
// 	}
// 	printf("Extracted map lines:\n");
// 	if (map_lines) {
// 		i = 0;
// 		while (map_lines[i]) {
// 			printf("  [%d]: '%s'\n", i, map_lines[i]);
// 			i++;
// 		}
// 		free_strarr(map_lines);
// 	} else {
// 		printf("  (NULL - extraction failed)\n");
// 	}
// 	free_strarr(lines);
// 	printf("\n=== Extract Map Lines Testing Complete ===\n");
// 	return (0);
// }
