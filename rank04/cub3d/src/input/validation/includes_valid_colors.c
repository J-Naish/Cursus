#include "../../../include/cub3d.h"

static bool	is_uint8(char *numstr)
{
	int	i;
	int	num;

	if (!numstr || !*numstr)
		return (false);
	if (ft_strlen(numstr) > 1 && numstr[0] == '0')
		return (false);
	i = 0;
	while (numstr[i])
	{
		if (!ft_isdigit(numstr[i]))
			return (false);
		i++;
	}
	if (i > 3)
		return (false);
	num = ft_atoi(numstr);
	if (num < 0 || num > 255)
		return (false);
	return (true);
}

static bool	valid_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (!is_uint8(rgb[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	valid_color_line(char *line, char *identifier)
{
	char	**rgb;

	rgb = ft_split(line + ft_strlen(identifier), ',');
	if (strarr_length(rgb) != 3)
		return (free_strarr(rgb), false);
	if (!valid_rgb(rgb))
		return (free_strarr(rgb), false);
	free_strarr(rgb);
	return (true);
}

bool	includes_valid_colors(char **lines)
{
	int	i;

	if (!includes_unique_identifier(lines, "F "))
		return (false);
	if (!includes_unique_identifier(lines, "C "))
		return (false);
	i = 0;
	while (lines[i])
	{
		if (starts_with(lines[i], "F ") && !valid_color_line(lines[i], "F "))
			return (false);
		if (starts_with(lines[i], "C ") && !valid_color_line(lines[i], "C "))
			return (false);
		i++;
	}
	return (true);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("=== Testing Color Validation ===\n");
// 	char **lines;
// 	char **color_arr;
// 	// Test valid_numstr function
// 	printf("Testing valid_numstr()...\n");
// 	assert(valid_numstr("0") == true);
// 	assert(valid_numstr("1") == true);
// 	assert(valid_numstr("10") == true);
// 	assert(valid_numstr("100") == true);
// 	assert(valid_numstr("255") == true);
// 	assert(valid_numstr("254") == true);
// 	assert(valid_numstr("128") == true);
// 	// Test invalid numbers
// 	assert(valid_numstr("256") == false);  // Too large
// 	assert(valid_numstr("1000") == false);  // Too many digits
// 	assert(valid_numstr("-1") == false);  // Negative
// 	assert(valid_numstr("01") == false);  // Leading zero
// 	assert(valid_numstr("001") == false);  // Leading zeros
// 	assert(valid_numstr("0255") == false);  // Leading zero
// 	assert(valid_numstr("") == false);  // Empty
// 	assert(valid_numstr(NULL) == false);  // NULL
// 	assert(valid_numstr("25a") == false);  // Non-digit
// 	assert(valid_numstr("a25") == false);  // Non-digit
// 	assert(valid_numstr("2.5") == false);  // Decimal
// 	assert(valid_numstr(" 25") == false);  // Space
// 	assert(valid_numstr("25 ") == false);  // Space
// 	// Test valid_color function
// 	printf("Testing valid_color()...\n");
// 	color_arr = malloc(sizeof(char *) * 4);
// 	color_arr[0] = "255";
// 	color_arr[1] = "128";
// 	color_arr[2] = "0";
// 	color_arr[3] = NULL;
// 	assert(valid_color(color_arr) == true);
// 	color_arr[0] = "256";  // Invalid
// 	assert(valid_color(color_arr) == false);
// 	color_arr[0] = "255";
// 	color_arr[1] = "01";  // Leading zero
// 	assert(valid_color(color_arr) == false);
// 	free(color_arr);
// 	// Test strarr_length function
// 	printf("Testing strarr_length()...\n");
// 	char *test_arr[] = {"one", "two", "three", NULL};
// 	assert(strarr_length(test_arr) == 3);
// 	char *empty_arr[] = {NULL};
// 	assert(strarr_length(empty_arr) == 0);
// 	// Test valid_coloring with complete lines
// 	printf("Testing valid_coloring()...\n");
// 	lines = malloc(sizeof(char *) * 5);
// 	lines[0] = "F 255,255,255";
// 	lines[1] = "C 0,0,0";
// 	lines[2] = "NO ./texture";
// 	lines[3] = "SO ./texture";
// 	lines[4] = NULL;
// 	assert(valid_coloring(lines, "F ") == true);
// 	assert(valid_coloring(lines, "C ") == true);
// 	// Test with invalid RGB values
// 	lines[0] = "F 256,255,255";  // 256 is invalid
// 	assert(valid_coloring(lines, "F ") == false);
// 	lines[0] = "F 255,255";  // Only 2 values
// 	assert(valid_coloring(lines, "F ") == false);
// 	lines[0] = "F 255,255,255,255";  // 4 values
// 	assert(valid_coloring(lines, "F ") == false);
// 	lines[0] = "F 255, 255, 255";  // Spaces around commas
// 	assert(valid_coloring(lines, "F ") == false);
// 	lines[0] = "F 255,01,255";  // Leading zero
// 	assert(valid_coloring(lines, "F ") == false);
// 	// Test includes_valid_colors
// 	printf("Testing includes_valid_colors()...\n");
// 	lines[0] = "F 220,100,0";
// 	lines[1] = "C 225,30,0";
// 	assert(includes_valid_colors(lines) == true);
// 	// Missing F
// 	lines[0] = "NO ./texture";
// 	assert(includes_valid_colors(lines) == false);
// 	// Duplicate F
// 	char **dup_lines = malloc(sizeof(char *) * 4);
// 	dup_lines[0] = "F 255,255,255";
// 	dup_lines[1] = "F 0,0,0";
// 	dup_lines[2] = "C 128,128,128";
// 	dup_lines[3] = NULL;
// 	assert(includes_valid_colors(dup_lines) == false);
// 	free(lines);
// 	free(dup_lines);
// 	printf("✅ All color validation tests passed!\n");
// 	return (0);
// }