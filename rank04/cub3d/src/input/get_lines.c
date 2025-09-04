#include "../../include/cub3d.h"

static int	count_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && content[i - 1] != '\n')
		count++;
	return (count);
}

static char	*extract_line(char *start, char *end)
{
	int		len;
	char	*line;
	int		i;

	if (end)
		len = end - start;
	else
		len = ft_strlen(start);
	if (len == 0)
		return (ft_strdup(""));
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = start[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	**split_lines(char *content)
{
	char	**lines;
	int		line_count;
	int		i;
	char	*next;

	line_count = count_lines(content);
	lines = calloc_strarr(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while (*content && i < line_count)
	{
		next = ft_strchr(content, '\n');
		lines[i] = extract_line(content, next);
		if (!lines[i])
			return (free_strarr(lines), NULL);
		if (next)
			content = next + 1;
		else
			content = content + ft_strlen(content);
		i++;
	}
	return (lines);
}

char	**get_lines(char *content)
{
	char	**lines;

	if (!content)
		return (NULL);
	lines = split_lines(content);
	return (lines);
}

// #include <stdio.h>
// #include <assert.h>
// #include <fcntl.h>
// #include <string.h>
// int main(void)
// {
// 	printf("=== Testing Read Lines with Real Maps ===\n");
// 	char **lines;
// 	int fd;
// 	int i;
// 	// Test 1: Simple map
// 	printf("Test 1: Reading simple.cub...\n");
// 	fd = open("maps/valid/simple.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open simple.cub\n");
// 		return (1);
// 	}
// 	lines = read_lines(fd);
// 	close(fd);
// 	assert(lines != NULL);
// 	// Check expected content
// 	assert(strcmp(lines[0], "NO ./textures/north.xpm") == 0);
// 	assert(strcmp(lines[1], "SO ./textures/south.xpm") == 0);
// 	assert(strcmp(lines[2], "WE ./textures/west.xpm") == 0);
// 	assert(strcmp(lines[3], "EA ./textures/east.xpm") == 0);
// 	assert(strcmp(lines[4], "F 220,100,0") == 0);
// 	assert(strcmp(lines[5], "C 225,30,0") == 0);
// 	assert(strcmp(lines[6], "") == 0);  // Empty line
// 	assert(strcmp(lines[7], "11111") == 0);
// 	assert(strcmp(lines[8], "10001") == 0);
// 	assert(strcmp(lines[9], "10N01") == 0);
// 	assert(strcmp(lines[10], "10001") == 0);
// 	assert(strcmp(lines[11], "11111") == 0);
// 	assert(lines[12] == NULL);
// 	free_strarr(lines);
// 	// Test 2: Minimal map
// 	printf("Test 2: Reading minimal.cub...\n");
// 	fd = open("maps/valid/minimal.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open minimal.cub\n");
// 		return (1);
// 	}
// 	lines = read_lines(fd);
// 	close(fd);
// 	assert(lines != NULL);
// 	assert(strcmp(lines[0], "NO ./n.xpm") == 0);
// 	assert(strcmp(lines[1], "SO ./s.xpm") == 0);
// 	assert(strcmp(lines[2], "WE ./w.xpm") == 0);
// 	assert(strcmp(lines[3], "EA ./e.xpm") == 0);
// 	assert(strcmp(lines[4], "F 0,0,0") == 0);
// 	assert(strcmp(lines[5], "C 255,255,255") == 0);
// 	assert(strcmp(lines[6], "") == 0);
// 	assert(strcmp(lines[7], "111") == 0);
// 	assert(strcmp(lines[8], "1N1") == 0);
// 	assert(strcmp(lines[9], "111") == 0);
// 	assert(lines[10] == NULL);
// 	free_strarr(lines);
// 	// Test 3: Map with empty lines (empty_lines.cub)
// 	printf("Test 3: Reading empty_lines.cub...\n");
// 	fd = open("maps/valid/empty_lines.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open empty_lines.cub\n");
// 		return (1);
// 	}
// 	lines = read_lines(fd);
// 	close(fd);
// 	assert(lines != NULL);
// 	// Check that empty lines are preserved
// 	assert(strcmp(lines[0], "NO ./textures/north.xpm") == 0);
// 	assert(strcmp(lines[1], "SO ./textures/south.xpm") == 0);
// 	assert(strcmp(lines[2], "") == 0);  // Empty line
// 	assert(strcmp(lines[3], "") == 0);  // Empty line
// 	assert(strcmp(lines[4], "WE ./textures/west.xpm") == 0);
// 	assert(strcmp(lines[5], "EA ./textures/east.xpm") == 0);
// 	assert(strcmp(lines[6], "") == 0);  // Empty line
// 	assert(strcmp(lines[7], "F 200,100,50") == 0);
// 	assert(strcmp(lines[8], "") == 0);  // Empty line
// 	assert(strcmp(lines[9], "C 100,200,250") == 0);
// 	assert(strcmp(lines[10], "") == 0);  // Empty line
// 	assert(strcmp(lines[11], "") == 0);  // Empty line
// 	// Map starts at line 12
// 	assert(strcmp(lines[12], "11111111111111111") == 0);
// 	free_strarr(lines);
// 	// Test 4: Map with spaces (with_spaces.cub)
// 	printf("Test 4: Reading with_spaces.cub...\n");
// 	fd = open("maps/valid/with_spaces.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open with_spaces.cub\n");
// 		return (1);
// 	}
// 	lines = read_lines(fd);
// 	close(fd);
// 	assert(lines != NULL);
// 	// Check map lines with spaces are preserved
// 	i = 0;
// 	while (lines[i] && !starts_with(lines[i], "11111111111111111111111111111"))
// 		i++;
// 	assert(lines[i] != NULL);  // Found map start
// 	// Check last two lines have spaces in them
// 	while (lines[i + 1])
// 		i++;
// 	// Last line should contain spaces between map sections
// 	assert(includes(lines[i], "11111111 1111111 11111111N111") == true);
// 	i--;
// 	assert(includes(lines[i], "11110111 1110101 101111010001") == true);
// 	free_strarr(lines);
// 	// Test 5: Invalid file descriptor
// 	printf("Test 5: Testing invalid file descriptor...\n");
// 	lines = read_lines(-1);
// 	assert(lines == NULL);
// 	// Test 6: Non-existent file
// 	printf("Test 6: Testing non-existent file...\n");
// 	fd = open("maps/valid/nonexistent.cub", O_RDONLY);
// 	assert(fd == -1);
// 	// Test 7: Large map file (large_maze.cub)
// 	printf("Test 7: Reading large_maze.cub...\n");
// 	fd = open("maps/valid/large_maze.cub", O_RDONLY);
// 	if (fd == -1) {
// 		printf("Failed to open large_maze.cub\n");
// 		return (1);
// 	}
// 	lines = read_lines(fd);
// 	close(fd);
// 	assert(lines != NULL);
// 	// Count lines
// 	i = 0;
// 	while (lines[i])
// 		i++;
// 	printf("Large maze has %d lines\n", i);
// 	assert(i > 50);  // Should be a large file
// 	// Check it has proper config
// 	assert(starts_with(lines[0], "NO ") == true);
// 	assert(starts_with(lines[1], "SO ") == true);
// 	assert(starts_with(lines[2], "WE ") == true);
// 	assert(starts_with(lines[3], "EA ") == true);
// 	assert(starts_with(lines[4], "F ") == true);
// 	assert(starts_with(lines[5], "C ") == true);
// 	free_strarr(lines);
// 	// Test 8: Check line count function indirectly
// 	printf("Test 8: Testing line counting...\n");
// 	fd = open("maps/valid/minimal.cub", O_RDONLY);
// 	lines = read_lines(fd);
// 	close(fd);
// 	i = 0;
// 	while (lines[i])
// 		i++;
// 	assert(i == 10);  // Minimal map should have exactly 10 lines
// 	free_strarr(lines);
// 	printf("✅ All read_lines tests passed!\n");
// 	return (0);
// }