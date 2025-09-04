#include "../../include/cub3d.h"

int	get_identifier_index(char **lines, char *identifier)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (starts_with(lines[i], identifier))
			return (i);
		i++;
	}
	return (-1);
}

bool	includes_unique_identifier(char **lines, char *identifier)
{
	bool	found;
	int		i;

	found = false;
	i = 0;
	while (lines[i])
	{
		if (starts_with(lines[i], identifier))
		{
			if (found)
				return (false);
			found = true;
		}
		i++;
	}
	return (found);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("=== Testing Identifier Functions ===\n");
// 	char **lines;
// 	int index;
// 	// Setup test data
// 	lines = malloc(sizeof(char *) * 10);
// 	lines[0] = "NO ./path/to/north.xpm";
// 	lines[1] = "SO ./path/to/south.xpm";
// 	lines[2] = "WE ./path/to/west.xpm";
// 	lines[3] = "EA ./path/to/east.xpm";
// 	lines[4] = "F 220,100,0";
// 	lines[5] = "C 225,30,0";
// 	lines[6] = "111111";
// 	lines[7] = "100001";
// 	lines[8] = "111111";
// 	lines[9] = NULL;
// 	// Test get_identifier_index - finding existing identifiers
// 	printf("Testing get_identifier_index() with existing identifiers...\n");
// 	index = get_identifier_index(lines, "NO ");
// 	assert(index == 0);
// 	index = get_identifier_index(lines, "SO ");
// 	assert(index == 1);
// 	index = get_identifier_index(lines, "WE ");
// 	assert(index == 2);
// 	index = get_identifier_index(lines, "EA ");
// 	assert(index == 3);
// 	index = get_identifier_index(lines, "F ");
// 	assert(index == 4);
// 	index = get_identifier_index(lines, "C ");
// 	assert(index == 5);
// 	// Test get_identifier_index - non-existing identifiers
// 	printf("Testing get_identifier_index() with non-existing identifiers...\n");
// 	index = get_identifier_index(lines, "NS ");
// 	assert(index == -1);
// 	index = get_identifier_index(lines, "NORTH ");
// 	assert(index == -1);
// 	index = get_identifier_index(lines, "N ");
// 	assert(index == -1);
// 	index = get_identifier_index(lines, "111");
// 	assert(index == 6);  // Map line starts with "111"
// 	// Test includes_unique_identifier - single occurrence
// 	printf("Testing includes_unique_identifier() with single occurrences...\n");
// 	assert(includes_unique_identifier(lines, "NO ") == true);
// 	assert(includes_unique_identifier(lines, "SO ") == true);
// 	assert(includes_unique_identifier(lines, "WE ") == true);
// 	assert(includes_unique_identifier(lines, "EA ") == true);
// 	assert(includes_unique_identifier(lines, "F ") == true);
// 	assert(includes_unique_identifier(lines, "C ") == true);
// 	// Test includes_unique_identifier - no occurrence
// 	printf("Testing includes_unique_identifier() with no occurrences...\n");
// 	assert(includes_unique_identifier(lines, "NS ") == false);
// 	assert(includes_unique_identifier(lines, "INVALID ") == false);
// 	assert(includes_unique_identifier(lines, "X ") == false);
// 	// Test includes_unique_identifier - duplicate identifiers
// 	printf("Testing includes_unique_identifier() with duplicates...\n");
// 	char **dup_lines = malloc(sizeof(char *) * 5);
// 	dup_lines[0] = "NO ./texture1";
// 	dup_lines[1] = "NO ./texture2";  // Duplicate NO
// 	dup_lines[2] = "SO ./texture";
// 	dup_lines[3] = "WE ./texture";
// 	dup_lines[4] = NULL;
// 	assert(includes_unique_identifier(dup_lines, "NO ") == false);
// 	assert(includes_unique_identifier(dup_lines, "SO ") == true);
// 	assert(includes_unique_identifier(dup_lines, "EA ") == false);
// 	// Test with empty lines array
// 	printf("Testing with empty lines array...\n");
// 	char **empty_lines = malloc(sizeof(char *) * 1);
// 	empty_lines[0] = NULL;
// 	index = get_identifier_index(empty_lines, "NO ");
// 	assert(index == -1);
// 	assert(includes_unique_identifier(empty_lines, "NO ") == false);
// 	// Test with identifiers that could be confused
// 	printf("Testing similar identifiers...\n");
// 	char **similar_lines = malloc(sizeof(char *) * 6);
// 	similar_lines[0] = "NO ./texture";
// 	similar_lines[1] = "NORTH ./wrong";  // Should not match "NO "
// 	similar_lines[2] = "N ./wrong";      // Should not match "NO "
// 	similar_lines[3] = "NON ./wrong";    // Should not match "NO "
// 	similar_lines[4] = "F 255,255,255";
// 	similar_lines[5] = NULL;
// 	assert(includes_unique_identifier(similar_lines, "NO ") == true);
// 	assert(includes_unique_identifier(similar_lines, "N ") == true);
// 	assert(includes_unique_identifier(similar_lines, "NORTH ") == true);
// 	// Test case sensitivity
// 	printf("Testing case sensitivity...\n");
// 	assert(includes_unique_identifier(lines, "no ") == false);
// 	assert(includes_unique_identifier(lines, "No ") == false);
// 	free(lines);
// 	free(dup_lines);
// 	free(empty_lines);
// 	free(similar_lines);
// 	printf("✅ All identifier tests passed!\n");
// 	return (0);
// }