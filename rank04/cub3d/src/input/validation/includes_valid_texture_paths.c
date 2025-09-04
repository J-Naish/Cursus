#include "../../../include/cub3d.h"

static bool	valid_path(char *path)
{
	int	i;

	if (!path || !*path)
		return (false);
	i = 0;
	while (path[i])
	{
		if (path[i] < 32 || path[i] > 126)
			return (false);
		i++;
	}
	return (true);
}

static bool	valid_texture_path(char **lines, char *identifier)
{
	int		index;
	char	*line;

	if (!includes_unique_identifier(lines, identifier))
		return (false);
	index = get_identifier_index(lines, identifier);
	line = lines[index];
	line += ft_strlen(identifier);
	if (!valid_path(line))
		return (false);
	return (true);
}

bool	includes_valid_texture_paths(char **lines)
{
	if (!valid_texture_path(lines, "NO "))
		return (false);
	if (!valid_texture_path(lines, "SO "))
		return (false);
	if (!valid_texture_path(lines, "WE "))
		return (false);
	if (!valid_texture_path(lines, "EA "))
		return (false);
	return (true);
}

// #include <stdio.h>
// #include <assert.h>
// #include <string.h>
// int main(void)
// {
// 	printf("=== Testing Texture Path Functions ===\n");
// 	// Test valid_path
// 	printf("Test 1: valid_path basic cases...\n");
// 	assert(valid_path("./textures/north.xpm") == true);
// 	assert(valid_path("textures/south.xpm") == true);
// 	assert(valid_path("simple.xpm") == true);
// 	assert(valid_path("path/with spaces.xpm") == true);
// 	assert(valid_path("\tfile.xpm") == false);  // Tab at start is printable
// 	assert(valid_path(" file.xpm") == true);   // Space at start is printable
// 	assert(valid_path("") == false);           // Empty path
// 	assert(valid_path(NULL) == false);         // NULL path
// 	// Test with control characters
// 	char bad_path[] = "file\x01.xpm";
// 	assert(valid_path(bad_path) == false);     // Non-printable character
// 	char bad_path2[] = "file\x7f.xpm";
// 	assert(valid_path(bad_path2) == false);    // DEL character
// 	// Test valid_texture_path
// 	printf("Test 2: valid_texture_path...\n");
// 	char *valid_lines[] = {
// 		"NO ./textures/north.xpm",
// 		"SO ./textures/south.xpm", 
// 		"WE ./textures/west.xpm",
// 		"EA ./textures/east.xpm",
// 		"F 220,100,0",
// 		"C 225,30,0",
// 		NULL
// 	};
// 	assert(valid_texture_path(valid_lines, "NO ") == true);
// 	assert(valid_texture_path(valid_lines, "SO ") == true);
// 	assert(valid_texture_path(valid_lines, "WE ") == true);
// 	assert(valid_texture_path(valid_lines, "EA ") == true);
// 	// Test duplicate identifier (should fail)
// 	char *duplicate_lines[] = {
// 		"NO ./textures/north1.xpm",
// 		"NO ./textures/north2.xpm",
// 		"SO ./textures/south.xpm",
// 		NULL
// 	};
// 	assert(valid_texture_path(duplicate_lines, "NO ") == false);
// 	// Test missing identifier (should fail)
// 	char *missing_lines[] = {
// 		"SO ./textures/south.xpm",
// 		"WE ./textures/west.xpm", 
// 		"EA ./textures/east.xpm",
// 		NULL
// 	};
// 	assert(valid_texture_path(missing_lines, "NO ") == false);
// 	// Test invalid path after identifier
// 	char *invalid_path_lines[] = {
// 		"NO ./textures/north.xpm",
// 		"SO ",  // Empty path after identifier
// 		"WE ./textures/west.xpm",
// 		NULL
// 	};
// 	assert(valid_texture_path(invalid_path_lines, "SO ") == false);
// 	// Test includes_valid_texture_paths
// 	printf("Test 3: includes_valid_texture_paths...\n");
// 	assert(includes_valid_texture_paths(valid_lines) == true);
// 	assert(includes_valid_texture_paths(duplicate_lines) == false);
// 	assert(includes_valid_texture_paths(missing_lines) == false);
// 	assert(includes_valid_texture_paths(invalid_path_lines) == false);
// 	// Test with minimal valid case
// 	char *minimal_lines[] = {
// 		"NO n.xpm",
// 		"SO s.xpm",
// 		"WE w.xpm", 
// 		"EA e.xpm",
// 		NULL
// 	};
// 	assert(includes_valid_texture_paths(minimal_lines) == true);
// 	// Test with extra whitespace/content after texture paths
// 	char *whitespace_lines[] = {
// 		"NO  ./path/with/double/space.xpm",
// 		"SO ./normal.xpm",
// 		"WE ./path.xpm   ",  // Trailing spaces
// 		"EA ./path.xpm",
// 		NULL
// 	};
// 	assert(includes_valid_texture_paths(whitespace_lines) == true);
// 	printf("✅ All texture_path tests passed!\n");
// 	return (0);
// }