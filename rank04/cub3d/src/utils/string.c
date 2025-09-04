#include "../../include/cub3d.h"

bool	includes(char *s, char *substr)
{
	int	i;
	int	j;

	if (!s || !substr)
		return (false);
	if (!*substr)
		return (true);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && substr[j] && s[i + j] == substr[j])
			j++;
		if (!substr[j])
			return (true);
		i++;
	}
	return (false);
}

bool	starts_with(char *s, char *prefix)
{
	int	i;

	if (!s || !prefix)
		return (false);
	if (!*prefix)
		return (true);
	i = 0;
	while (prefix[i])
	{
		if (!s[i] || s[i] != prefix[i])
			return (false);
		i++;
	}
	return (true);
}

bool	ends_with(char *str, char *ending)
{
	size_t	str_len;
	size_t	ending_len;

	if (!str || !ending)
		return (false);
	str_len = ft_strlen(str);
	ending_len = ft_strlen(ending);
	if (str_len < ending_len)
		return (false);
	return (ft_strncmp(str + str_len - ending_len, ending, ending_len) == 0);
}

bool	equals(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("=== Testing String Utils ===\n");
// 	// Test includes function
// 	printf("Testing includes()...\n");
// 	assert(includes("hello world", "world") == true);
// 	assert(includes("hello world", "World") == false);
// 	assert(includes("hello world", "lo wo") == true);
// 	assert(includes("hello", "llo") == true);
// 	assert(includes("hello", "hello") == true);
// 	assert(includes("hello", "helloz") == false);
// 	assert(includes("", "") == true);
// 	assert(includes("test", "") == true);
// 	assert(includes("", "test") == false);
// 	assert(includes(NULL, "test") == false);
// 	assert(includes("test", NULL) == false);
// 	// Test starts_with function
// 	printf("Testing starts_with()...\n");
// 	assert(starts_with("hello world", "hello") == true);
// 	assert(starts_with("hello world", "Hello") == false);
// 	assert(starts_with("hello world", "world") == false);
// 	assert(starts_with("hello", "hello") == true);
// 	assert(starts_with("hello", "hello world") == false);
// 	assert(starts_with("test", "") == true);
// 	assert(starts_with("", "") == true);
// 	assert(starts_with("", "test") == false);
// 	assert(starts_with(NULL, "test") == false);
// 	assert(starts_with("test", NULL) == false);
// 	assert(starts_with("NO ./texture", "NO ") == true);
// 	assert(starts_with("F 255,255,255", "F ") == true);
// 	// Test ends_with function
// 	printf("Testing ends_with()...\n");
// 	assert(ends_with("hello world", "world") == true);
// 	assert(ends_with("hello world", "World") == false);
// 	assert(ends_with("hello world", "hello") == false);
// 	assert(ends_with("test.cub", ".cub") == true);
// 	assert(ends_with("test.cub", ".CUB") == false);
// 	assert(ends_with("test", "test") == true);
// 	assert(ends_with("test", "testing") == false);
// 	assert(ends_with("", "") == true);
// 	assert(ends_with("test", "") == true);
// 	assert(ends_with("", "test") == false);
// 	assert(ends_with(NULL, "test") == false);
// 	assert(ends_with("test", NULL) == false);
// 	// Test equals function
// 	printf("Testing equals()...\n");
// 	assert(equals("hello", "hello") == true);
// 	assert(equals("hello", "Hello") == false);
// 	assert(equals("hello", "world") == false);
// 	assert(equals("", "") == true);
// 	assert(equals("test", "test ") == false);
// 	assert(equals(" test", "test") == false);
// 	assert(equals("hello", "hell") == false);
// 	assert(equals("hell", "hello") == false);
// 	assert(equals(NULL, "test") == false);
// 	assert(equals("test", NULL) == false);
// 	assert(equals(NULL, NULL) == false);
// 	// Test free_strarr function
// 	printf("Testing free_strarr()...\n");
// 	char **arr = malloc(sizeof(char *) * 4);
// 	arr[0] = ft_strdup("first");
// 	arr[1] = ft_strdup("second");
// 	arr[2] = ft_strdup("third");
// 	arr[3] = NULL;
// 	free_strarr(arr);
// 	// No assertion needed, just checking it doesn't crash
// 	printf("✅ All string utils tests passed!\n");
// 	return (0);
// }
