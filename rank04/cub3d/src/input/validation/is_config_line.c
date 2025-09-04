#include "../../../include/cub3d.h"

bool	is_config_line(char *line)
{
	if (starts_with(line, "NO "))
		return (true);
	else if (starts_with(line, "SO "))
		return (true);
	else if (starts_with(line, "EA "))
		return (true);
	else if (starts_with(line, "WE "))
		return (true);
	else if (starts_with(line, "F "))
		return (true);
	else if (starts_with(line, "C "))
		return (true);
	else
		return (false);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("=== Testing Validation Utils ===\n");
// 	// Test is_config_line
// 	printf("Testing is_config_line()...\n");
// 	// Valid config lines
// 	assert(is_config_line("NO ./path/to/texture") == true);
// 	assert(is_config_line("SO ./path/to/texture") == true);
// 	assert(is_config_line("WE ./path/to/texture") == true);
// 	assert(is_config_line("EA ./path/to/texture") == true);
// 	assert(is_config_line("F 255,255,255") == true);
// 	assert(is_config_line("C 0,0,0") == true);
// 	// Invalid config lines
// 	assert(is_config_line("NO") == false);  // Missing space
// 	assert(is_config_line("NO./texture") == false);
// 	assert(is_config_line("N ./texture") == false);
// 	assert(is_config_line("NORTH ./texture") == false);
// 	assert(is_config_line("F255,255,255") == false);
// 	assert(is_config_line("Floor 255,255,255") == false);
// 	assert(is_config_line("111111") == false);  // Map line
// 	assert(is_config_line("") == false);  // Empty line
// 	assert(is_config_line("   ") == false);  // Spaces only
// 	assert(is_config_line("#comment") == false);  // Comment
// 	// Case sensitivity
// 	assert(is_config_line("no ./texture") == false);  // lowercase
// 	assert(is_config_line("No ./texture") == false);  // mixed case
// 	return (0);
// }