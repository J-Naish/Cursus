#include "../../../include/cub3d.h"

static bool	valid_arg(int argc)
{
	if (argc == 2)
		return (true);
	else
		return (false);
}

static bool	valid_filename(char *map_path)
{
	char	*last_slash;
	char	*filename;

	if (!map_path || !*map_path)
		return (false);
	last_slash = ft_strrchr(map_path, '/');
	if (last_slash)
		filename = last_slash + 1;
	else
		filename = map_path;
	if (ft_strlen(filename) <= ft_strlen(".cub"))
		return (false);
	return (ends_with(filename, ".cub"));
}

void	validate_arg(int argc, char **argv)
{
	if (!valid_arg(argc))
		exit_with_error_msg("Error\nInvalid argument: ./cub3D <map path>\n");
	if (!valid_filename(argv[1]))
		exit_with_error_msg("Error\nInvalid filename: expects *.cub\n");
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("=== Testing Argument Validation ===\n");
// 	// Test valid_arg function
// 	printf("Testing valid_arg()...\n");
// 	assert(valid_arg(2) == true);
// 	assert(valid_arg(1) == false);
// 	assert(valid_arg(0) == false);
// 	assert(valid_arg(3) == false);
// 	assert(valid_arg(10) == false);
// 	assert(valid_arg(-1) == false);
// 	// Test valid_filename with valid .cub files
// 	printf("Testing valid_filename() with valid files...\n");
// 	assert(valid_filename("map.cub") == true);
// 	assert(valid_filename("test.cub") == true);
// 	assert(valid_filename("my_map.cub") == true);
// 	assert(valid_filename("./maps/test.cub") == true);
// 	assert(valid_filename("/home/user/maps/test.cub") == true);
// 	assert(valid_filename("../maps/test.cub") == true);
// 	assert(valid_filename("a.cub") == true);
// 	assert(valid_filename(
//		"very_long_filename_with_many_characters.cub") == true);
// 	// Test valid_filename with paths
// 	printf("Testing valid_filename() with paths...\n");
// 	assert(valid_filename("/path/to/map.cub") == true);
// 	assert(valid_filename("./relative/path/map.cub") == true);
// 	assert(valid_filename("../../maps/valid/test.cub") == true);
// 	assert(valid_filename("/maps/.cub") == false);
// 	// Test valid_filename with invalid extensions
// 	printf("Testing valid_filename() with invalid extensions...\n");
// 	assert(valid_filename("map.txt") == false);
// 	assert(valid_filename("map.CUB") == false);  // Case sensitive
// 	assert(valid_filename("map.cub.txt") == false);
// 	assert(valid_filename("mapcub") == false);
// 	assert(valid_filename("map.") == false);
// 	assert(valid_filename("map") == false);
// 	assert(valid_filename(".cub") == false);  // Only extension
// 	// Test valid_filename with edge cases
// 	printf("Testing valid_filename() edge cases...\n");
// 	assert(valid_filename("") == false);
// 	assert(valid_filename(NULL) == false);
// 	assert(valid_filename("cub") == false);
// 	assert(valid_filename("xcub") == false);
// 	assert(valid_filename("map.xcub") == false);
// 	assert(valid_filename("map.cubx") == false);
// 	// Test with special characters in filename
// 	printf("Testing valid_filename() with special characters...\n");
// 	assert(valid_filename("map-1.cub") == true);
// 	assert(valid_filename("map_2.cub") == true);
// 	assert(valid_filename("map 3.cub") == true);  // Space in filename
// 	assert(valid_filename("map(1).cub") == true);
// 	// Test validate_arg function (without exit)
// 	printf("Testing validate_arg() logic...\n");
// 	// Note: Can't test validate_arg directly as it calls exit
// 	// But we've tested its component functions thoroughly
// 	printf("Component functions tested successfully\n");
// 	printf("✅ All argument validation tests passed!\n");
// 	return (0);
// }