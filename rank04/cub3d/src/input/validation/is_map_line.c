#include "../../../include/cub3d.h"

bool	is_map_line(char *s)
{
	int		i;
	bool	has_non_void;

	if (!s || !*s)
		return (false);
	has_non_void = false;
	i = 0;
	while (s[i])
	{
		if (!is_map_symbol(s[i]))
			return (false);
		if (s[i] != VOID)
			has_non_void = true;
		i++;
	}
	return (has_non_void);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("Testing is_map_line()...\n");
// 	// Valid map lines
// 	assert(is_map_line("111111") == true);
// 	assert(is_map_line("100001") == true);
// 	assert(is_map_line("10N001") == true);  // With player North
// 	assert(is_map_line("10S001") == true);  // With player South
// 	assert(is_map_line("10E001") == true);  // With player East
// 	assert(is_map_line("10W001") == true);  // With player West
// 	assert(is_map_line("1 0 0 1") == true);  // With spaces (void)
// 	assert(is_map_line("    111111") == true);  // Leading spaces
// 	assert(is_map_line("111111    ") == true);  // Trailing spaces
// 	assert(is_map_line(" 1 0 N 0 1 ") == true);  // Mixed
// 	// Invalid map lines
// 	assert(is_map_line("") == false);  // Empty string
// 	assert(is_map_line("   ") == false);  // Only spaces (no non-void)
// 	assert(is_map_line("        ") == false);  // Only spaces
// 	assert(is_map_line("1234") == false);  // Invalid characters
// 	assert(is_map_line("10X01") == false);  // Invalid player direction
// 	assert(is_map_line("10n01") == false);  // Lowercase player
// 	assert(is_map_line("NO ./texture") == false);  // Config line
// 	assert(is_map_line("F 255,255,255") == false);  // Config line
// 	assert(is_map_line("#111111") == false);  // Comment
// 	assert(is_map_line("111\t111") == false);  // Tab character
// 	assert(is_map_line("111\n111") == false);  // Newline
// 	assert(is_map_line("1.0.1") == false);  // Dots
// 	assert(is_map_line("1,0,1") == false);  // Commas
// 	// Edge cases
// 	assert(is_map_line("1") == true);  // Single wall
// 	assert(is_map_line("0") == true);  // Single empty
// 	assert(is_map_line("N") == true);  // Single player
// 	assert(is_map_line(" ") == false);  // Single space (no non-void)
// 	assert(is_map_line(" 1") == true);  // Space then wall
// 	assert(is_map_line("1 ") == true);  // Wall then space
// 	// Test that at least one non-void character is required
// 	printf("Testing non-void requirement...\n");
// 	assert(is_map_line(" ") == false);
// 	assert(is_map_line("  ") == false);
// 	assert(is_map_line("   ") == false);
// 	assert(is_map_line(" 0") == true);  // Has non-void
// 	assert(is_map_line(" 1") == true);  // Has non-void
// 	assert(is_map_line(" N") == true);  // Has non-void
// 	// NULL handling
// 	assert(is_map_line(NULL) == false);
// 	assert(is_config_line(NULL) == false);
// 	printf("✅ All validation utils tests passed!\n");
// 	return (0);
// }