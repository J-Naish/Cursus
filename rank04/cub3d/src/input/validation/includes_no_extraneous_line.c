#include "../../../include/cub3d.h"

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static bool	includes_only_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	includes_no_extraneous_line(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (includes_only_space(lines[i]))
		{
			i++;
			continue ;
		}
		if (!is_config_line(lines[i]) && !is_map_line(lines[i]))
			return (false);
		i++;
	}
	return (true);
}

// #include <stdio.h>
// #include <assert.h>
// #include <string.h>
// int main(void)
// {
// 	printf("=== Testing Extraneous Lines Validation ===\n");
// 	char **lines;
// 	// Test is_space function
// 	printf("Testing is_space()...\n");
// 	assert(is_space(' ') == true);
// 	assert(is_space('\t') == true);
// 	assert(is_space('\n') == true);
// 	assert(is_space('\v') == true);
// 	assert(is_space('\f') == true);
// 	assert(is_space('\r') == true);
// 	assert(is_space('a') == false);
// 	assert(is_space('0') == false);
// 	assert(is_space('1') == false);
// 	assert(is_space('N') == false);
// 	assert(is_space('.') == false);
// 	assert(is_space('/') == false);
// 	// Test includes_only_space function
// 	printf("Testing includes_only_space()...\n");
// 	assert(includes_only_space("") == true);  // Empty is all spaces
// 	assert(includes_only_space(" ") == true);
// 	assert(includes_only_space("   ") == true);
// 	assert(includes_only_space("\t") == true);
// 	assert(includes_only_space("\t\t") == true);
// 	assert(includes_only_space(" \t ") == true);
// 	assert(includes_only_space("\n") == true);
// 	assert(includes_only_space(" \n\t") == true);
// 	assert(includes_only_space("\r\n") == true);
// 	assert(includes_only_space(" a ") == false);
// 	assert(includes_only_space("NO") == false);
// 	assert(includes_only_space("111") == false);
// 	assert(includes_only_space("0") == false);
// 	// Test includes_no_extraneous_line with valid config file
// 	printf("Testing includes_no_extraneous_line() with valid config...\n");
// 	lines = malloc(sizeof(char *) * 12);
// 	lines[0] = "NO ./path/to/north.xpm";
// 	lines[1] = "SO ./path/to/south.xpm";
// 	lines[2] = "WE ./path/to/west.xpm";
// 	lines[3] = "EA ./path/to/east.xpm";
// 	lines[4] = "";  // Empty line
// 	lines[5] = "F 220,100,0";
// 	lines[6] = "C 225,30,0";
// 	lines[7] = "   ";  // Only spaces
// 	lines[8] = "111111";  // Map line
// 	lines[9] = "100001";  // Map line
// 	lines[10] = "111111";  // Map line
// 	lines[11] = NULL;
// 	assert(includes_no_extraneous_line(lines) == true);
// 	// Test with invalid line (not config or map)
// 	printf("Testing with invalid lines...\n");
// 	lines[4] = "INVALID LINE";
// 	assert(includes_no_extraneous_line(lines) == false);
// 	lines[4] = "N ./texture";  // Missing 'O' in NO
// 	assert(includes_no_extraneous_line(lines) == false);
// 	lines[4] = "Floor 255,255,255";  // Should be just 'F'
// 	assert(includes_no_extraneous_line(lines) == false);
// 	lines[4] = "#comment";  // Comments not allowed
// 	assert(includes_no_extraneous_line(lines) == false);
// 	lines[4] = "1234";  // Invalid map chars
// 	assert(includes_no_extraneous_line(lines) == false);
// 	// Test with mixed valid content
// 	printf("Testing mixed valid content...\n");
// 	lines[0] = "NO ./texture";
// 	lines[1] = "";  // Empty
// 	lines[2] = "SO ./texture";
// 	lines[3] = "\t\t";  // Only tabs
// 	lines[4] = "WE ./texture";
// 	lines[5] = "EA ./texture";
// 	lines[6] = "F 255,255,255";
// 	lines[7] = "C 0,0,0";
// 	lines[8] = "";  // Empty before map
// 	lines[9] = "11111";
// 	lines[10] = "10N01";
// 	lines[11] = NULL;
// 	assert(includes_no_extraneous_line(lines) == true);
// 	// Test map with spaces
// 	printf("Testing map lines with spaces...\n");
// 	lines[0] = "    1111111";  // Map line with leading spaces
// 	lines[1] = "    1000001";
// 	lines[2] = "    1111111";
// 	lines[3] = NULL;
// 	assert(includes_no_extraneous_line(lines) == true);
// 	// Test only whitespace lines
// 	printf("Testing only whitespace lines...\n");
// 	char **space_lines = malloc(sizeof(char *) * 5);
// 	space_lines[0] = "";
// 	space_lines[1] = " ";
// 	space_lines[2] = "\t";
// 	space_lines[3] = "   \t   ";
// 	space_lines[4] = NULL;
// 	assert(includes_no_extraneous_line(space_lines) == true);
// 	free(lines);
// 	free(space_lines);
// 	printf("✅ All extraneous lines tests passed!\n");
// 	return (0);
// }