#include "../../../include/cub3d.h"

bool	ends_with_map(char **lines)
{
	bool	map_found;
	int		i;

	map_found = false;
	i = 0;
	while (lines[i])
	{
		if (map_found && is_config_line(lines[i]))
			return (false);
		if (is_map_line(lines[i]))
			map_found = true;
		i++;
	}
	return (map_found);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("=== Testing Order Validation ===\n");
// 	char **lines;
// 	// Test 1: Valid order - config then map
// 	printf("Test 1: Valid order (config then map)...\n");
// 	lines = malloc(sizeof(char *) * 10);
// 	lines[0] = "NO ./texture";
// 	lines[1] = "SO ./texture";
// 	lines[2] = "WE ./texture";
// 	lines[3] = "EA ./texture";
// 	lines[4] = "F 255,255,255";
// 	lines[5] = "C 0,0,0";
// 	lines[6] = "111111";
// 	lines[7] = "100001";
// 	lines[8] = "111111";
// 	lines[9] = NULL;
// 	assert(ends_with_map(lines) == true);
// 	// Test 2: Invalid order - config after map
// 	printf("Test 2: Invalid order (config after map)...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "111111";  // Map line
// 	lines[2] = "100001";  // Map line
// 	lines[3] = "SO ./texture";  // Config after map - invalid!
// 	lines[4] = NULL;
// 	assert(ends_with_map(lines) == false);
// 	// Test 3: No map at all
// 	printf("Test 3: No map (only config)...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "SO ./texture";
// 	lines[2] = "WE ./texture";
// 	lines[3] = "EA ./texture";
// 	lines[4] = "F 255,255,255";
// 	lines[5] = "C 0,0,0";
// 	lines[6] = NULL;
// 	assert(ends_with_map(lines) == false);
// 	// Test 4: Only map, no config
// 	printf("Test 4: Only map lines...\n");
// 	lines[0] = "111111";
// 	lines[1] = "100001";
// 	lines[2] = "111111";
// 	lines[3] = NULL;
// 	assert(ends_with_map(lines) == true);
// 	// Test 5: Empty lines between config and map
// 	printf("Test 5: Empty lines between sections...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "SO ./texture";
// 	lines[2] = "";  // Empty line
// 	lines[3] = "";  // Empty line
// 	lines[4] = "111111";
// 	lines[5] = "100001";
// 	lines[6] = NULL;
// 	assert(ends_with_map(lines) == true);
// 	// Test 6: Mixed order - invalid
// 	printf("Test 6: Mixed order (config-map-config)...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "111111";
// 	lines[2] = "100001";
// 	lines[3] = "WE ./texture";  // Config after map
// 	lines[4] = "EA ./texture";  // Config after map
// 	lines[5] = NULL;
// 	assert(ends_with_map(lines) == false);
// 	// Test 7: Map with player position
// 	printf("Test 7: Map with player position...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "SO ./texture";
// 	lines[2] = "WE ./texture";
// 	lines[3] = "EA ./texture";
// 	lines[4] = "F 255,255,255";
// 	lines[5] = "C 0,0,0";
// 	lines[6] = "11111";
// 	lines[7] = "10N01";  // Map with player
// 	lines[8] = "11111";
// 	lines[9] = NULL;
// 	assert(ends_with_map(lines) == true);
// 	// Test 8: Empty file
// 	printf("Test 8: Empty file...\n");
// 	char **empty = malloc(sizeof(char *) * 1);
// 	empty[0] = NULL;
// 	assert(ends_with_map(empty) == false);
// 	// Test 9: Config line appears after multiple map lines
// 	printf("Test 9: Config after multiple map lines...\n");
// 	lines[0] = "111111";
// 	lines[1] = "100001";
// 	lines[2] = "100001";
// 	lines[3] = "100001";
// 	lines[4] = "111111";
// 	lines[5] = "F 255,255,255";  // Config after map
// 	lines[6] = NULL;
// 	assert(ends_with_map(lines) == false);
// 	// Test 10: Map with spaces
// 	printf("Test 10: Map with leading spaces...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "SO ./texture";
// 	lines[2] = "WE ./texture";
// 	lines[3] = "EA ./texture";
// 	lines[4] = "F 255,255,255";
// 	lines[5] = "C 0,0,0";
// 	lines[6] = "    111111";  // Map with leading spaces
// 	lines[7] = "    100001";
// 	lines[8] = "    111111";
// 	lines[9] = NULL;
// 	assert(ends_with_map(lines) == true);
// 	// Test 11: Only whitespace lines (no map)
// 	// A valid map line must contain at least one non-void character
// 	printf("Test 11: Only whitespace lines...\n");
// 	char **space_lines = malloc(sizeof(char *) * 4);
// 	space_lines[0] = "";
// 	space_lines[1] = "   ";
// 	space_lines[2] = "\t";
// 	space_lines[3] = NULL;
// 	assert(ends_with_map(space_lines) == false);
// 	free(lines);
// 	free(empty);
// 	free(space_lines);
// 	printf("✅ All order validation tests passed!\n");
// 	return (0);
// }